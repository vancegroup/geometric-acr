#!/usr/bin/env lua

--- Call like:
--- ./generate_cmake_in.lua > RecognizeLimitedConstraints.cpp.cmake_in

--- Generates RecognizeLimitedConstraints.cpp.cmake_in (to stdout)
--- primarily based on the "recognizers" table below as well as
--- the various code templates used in the second half of the file.

function common(t)
    t.header = ([[<boundary_features/detail/RecognizedPairs/%s.h>]]):format(t.name)
    return t
end

function symm(recognizername)
    return common{
        name = recognizername,
        symmetric = true
    }
end

function asymm(recognizername)
    return common{
        name = recognizername,
        symmetric = false
    }
end

function makeNumbered(i, str)
    local x = str:gsub("#i#", ("%d"):format(i))
    return x
end

function printNumbered(i, str)
    print(makeNumbered(i, str))
end

recognizers = {
    asymm "CircleCylinder";
    symm "CylinderCylinder";
    symm "ConeCone";
    symm "PlanePlane";
    asymm "SphereCylinder";
    symm "SphereSphere";
}

bits = #recognizers

-- Iterate through each recognizer, giving bit number and recognizer to function.
-- If function returns anything, stick it in a table, letting us use this like "map"
function foreachbit(func)
    local t = {}
    for i=0, #recognizers-1 do
        local x = func(i, recognizers[i + 1])
        if x ~= nil then
            table.insert(t, x)
        end
    end
    return t
end
print[[/**
	@file
	@brief Configurable/configured implementation of recognizer
	       with specific constraints turned on or off.

	       Configurable (.cmake_in) file generated by Lua script.

	       No matter how/where you see this file, DO NOT EDIT BY HAND!
	       Instead edit the Lua script, or the CMakeLists file.


	@date 2014

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

//          Copyright Iowa State University 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BF_EXPERIMENT

#include <RecognizeLimitedConstraints.h>

#include <boundary_features/RecognizeConstraints.h>
#include <boundary_features/BoundaryFeatures.h>
#include <boundary_features/detail/BinaryConstraintVisitor.h>

#cmakedefine BF_EXPERIMENT_CONDITION=BF_EXPERIMENT_CONDITION

]]

print(([[
// Built-in compile-time consistency check
#if BF_NUM_BITS != %d
#  error "CMake doesn't agree with lua/generated file on how many bits there are!"
#endif
]]):format(bits))



-- For each recognizer/bit, write a cmakedefine
foreachbit(function(i)
    printNumbered(i,"#cmakedefine BF_EXPERIMENT_R#i#=BF_EXPERIMENT_R#i#")
end)

-- Blank
print()

-- For each recognizer/bit, write conditional include, as well as accounting.
foreachbit(function(i, recog)
    -- Print conditional include
    print(makeNumbered(i, [[
#if BF_EXPERIMENT_R#i#
#include %s
#endif]]):format(recog.header))

    -- Print preprocessor stuff to count # of symmetric and asymmetric
    if recog.symmetric then
        printNumbered(i, [[
#define BF_EXPERIMENT_R#i#_SYMM BF_EXPERIMENT_R#i#
#define BF_EXPERIMENT_R#i#_ASYMM 0
]])
    else
        printNumbered(i, [[
#define BF_EXPERIMENT_R#i#_SYMM 0
#define BF_EXPERIMENT_R#i#_ASYMM BF_EXPERIMENT_R#i#
]])
    end
end)

-- Blank
print()

-- Print names into an array for good measure.
print([[static const char * const names[] = {]] ..
    table.concat(foreachbit(function(i, recog) return ([["%s"]]):format(recog.name) end), ", ") ..
    [[};]])

print [[const char * getName(size_t i) { return names[i]; }]]

print [[size_t getExperimentCondition() { return BF_EXPERIMENT_CONDITION; }]]

-- Total number of symmetric enabled
local expression = table.concat(foreachbit(function(i, recog) return makeNumbered(i, "BF_EXPERIMENT_R#i#_SYMM") end), " + ")
print([[size_t getNumSymmetric() { return ]] .. expression .. [[; }]])

-- Similarly for asymmetric
local expression = table.concat(foreachbit(function(i, recog) return makeNumbered(i, "BF_EXPERIMENT_R#i#_ASYMM") end), " + ")
print([[size_t getNumAsymmetric() { return ]] .. expression .. [[; }]])

print( ([[size_t getNumBits() { return %d; }]]):format(bits))

