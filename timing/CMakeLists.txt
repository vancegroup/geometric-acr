set(COMMON_LIB_SOURCE
    ../boundary_features/Circle.cpp
    ../boundary_features/Cone.cpp
    ../boundary_features/ConstraintSet.cpp
    ../boundary_features/Cylinder.cpp
    ../boundary_features/CylindricalConstraint.cpp
    ../boundary_features/GeometricConstraint.cpp
    # Intentionally skipping RecognizeConstraints
    ../boundary_features/Plane.cpp
    ../boundary_features/Sphere.cpp)

set(COMMON_EXEC_SOURCE
    main.cpp
    DataRowOutputter.h
    DataRowOutputter.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# number of recognizers
set(BF_NUM_BITS 6)
add_definitions(-DBF_NUM_BITS=${BF_NUM_BITS})
message(STATUS "Timing experiment: ${BF_NUM_BITS} bits to manipulate")

# Make a list of bit indices, and also compute 2 to the power of BF_NUM_BITS
# since CMake's math ^ is xor, not exponent.
set(BITS)
set(bit 0)
set(MAX_ITER 1)
while(bit LESS BF_NUM_BITS)
    list(APPEND BITS ${bit})
    math(EXPR MAX_ITER "${MAX_ITER} * 2")
    math(EXPR bit "${bit} + 1")
endwhile()

message(STATUS "Timing experiment: ${MAX_ITER} total conditions")
message(STATUS "Timing experiment: building with ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")


set(cond 0)
while(cond LESS MAX_ITER)
    set(BF_EXPERIMENT_CONDITION ${cond})

    # Take the condition and extract each bit as on/off for a constraint recognizer
    foreach(bit ${BITS})
        # Get the value of bit in cond.
        math(EXPR val "(${cond} & (1 << ${bit}) ) >> ${bit}")
        set(BF_EXPERIMENT_R${bit} ${val})
    endforeach()

    # Make the custom recognizer library.
    set(LIBNAME ConstraintRecognizer_Condition${cond})
    set(GENERATED_FILE "${CMAKE_CURRENT_BINARY_DIR}/RecognizeLimitedConstraints_${cond}.cpp")
    configure_file(RecognizeLimitedConstraints.cpp.cmake_in "${GENERATED_FILE}")
    add_library(${LIBNAME} STATIC "${GENERATED_FILE}" ${COMMON_LIB_SOURCE})

    # Make the custom executable - nothing special except what it links to.
    set(EXECNAME perform_condition_${cond}_timing)
    add_executable(${EXECNAME} ${COMMON_EXEC_SOURCE})
    target_link_libraries(${EXECNAME} ${LIBNAME})

    math(EXPR cond "${cond} + 1")
endwhile()
