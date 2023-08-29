cmake_minimum_required(VERSION 3.19)
project(Leetcode)

set(CMAKE_CXX_STANDARD 14)

# 遍历项目根目录下所有的 .cpp 文件
file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)/(.+)\\..*" "\\1-\\2" exe ${file})
    add_executable (${exe} ${file} Medium/LeetCode106.h Medium/KnapsackProblem.h Medium/LeetCode15.h Medium/LeetCode17.h Medium/LeetCode18.h Medium/LeetCode19.h Medium/LeetCode24.h Medium/LeetCode28.h Medium/LeetCode39.h Medium/LeetCode40.h Medium/LeetCode45.h Medium/LeetCode46.h Medium/LeetCode47.h Medium/LeetCode53.h Medium/LeetCode55.h Medium/LeetCode56.h Medium/LeetCode59.h Medium/LeetCode62.h Medium/LeetCode63.h Medium/LeetCode77.h Medium/LeetCode78.h Medium/LeetCode90.h Medium/LeetCode93.h Medium/LeetCode96.h Medium/LeetCode98.h Medium/LeetCode102.h Medium/Leetcode105.h Medium/LeetCode122.h Medium/LeetCode131.h Medium/LeetCode134.h Medium/LeetCode142.h Medium/LeetCode150.h Medium/LeetCode151.h Medium/LeetCode216.h Medium/LeetCode222.h Medium/LeetCode235.h Medium/LeetCode236.h Medium/LeetCode343.h Medium/LeetCode347.h Medium/LeetCode376.h Medium/LeetCode406.h Medium/LeetCode416.h Medium/LeetCode435.h Medium/LeetCode450.h Medium/LeetCode452.h Medium/LeetCode454.h Medium/LeetCode491.h Medium/LeetCode513.h Medium/LeetCode538.h Medium/LeetCode654.h Medium/LeetCode669.h Medium/LeetCode701.h Medium/LeetCode738.h Medium/LeetCode763.h Medium/LeetCode1049.h Medium/LeetCode494.h Medium/LeetCode474.h Medium/LeetCode518.h Medium/LeetCode377.h Easy/LeetCode70.h Medium/LeetCode322.h Medium/LeetCode279.h Medium/LeetCode139.h Medium/LeetCode198.h Medium/LeetCode213.h Medium/LeetCode337.h
            Easy/LeetCode121.h
            Medium/LeetCode309.h
            Medium/LeetCode714.h
            Medium/LeetCode300.h
            Easy/LeetCode674.h
            Medium/LeetCode718.h
            Medium/LeetCode1143.h
            Medium/LeetCode1035.h
            Medium/LeetCode392.h
            Medium/LeetCode583.h
            Hard/LeetCode72.h
            Medium/LeetCode647.h
            Medium/LeetCode516.h)
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()