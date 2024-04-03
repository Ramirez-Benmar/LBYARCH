# LBYARCH
LBYARCH Programming Project

x86-to-C interface programming project

# Requirements

Write the kernel in (1) C program and (2) an x86-64 assembly language.  The kernel is to perform a dot product between vector A and vector B and place the result in sdot.

Input: Scalar variable n (integer) contains the length of the vector;  Vectors A and B are both double-precision float. Scalar sdot is a double-precision float.

![image](https://github.com/Ramirez-Benmar/LBYARCH/assets/134592419/405651f6-74d5-42fd-ae77-934b2e4d3cfa)

Output: store the result in memory location sdot.  Display the result for all versions of the kernel (i.e., C and  x86-64).

# Analysis

FOR DEBUGGING

![image](https://github.com/Ramirez-Benmar/LBYARCH/assets/134592419/45fb36ad-e647-4245-9e1f-455a5488f292)

In the debug process, we decided to execute starting from the vector size of 2^20 to 2^28 to ensure that it would generate every value and render the prompt to freeze. 

Based from the above screenshot, it appears that the Assembly function is 300% faster in ms than the C function.

FOR RELEASING

![image](https://github.com/Ramirez-Benmar/LBYARCH/assets/134592419/a259dc50-c092-426b-a526-e709b00587df)

In the release process, we decided to do the same thing where we executed starting from 2^20 until 2^28 to ensure that it wouldn't freeze.

The Assembly function continues to perform better but there was a significant decrease in speed, which is why the gap tightened between the times between the two programs. The C function did perform better than in the debug process. Clearly the assembly function is still faster in both functions for debugging and releasing.

# Conclusion

Based on the analysis we did for Debugging and Releasing, the Assembly program outperformed the C program. The results also show that the Assembly program ran a lot faster in debug mode than in the release process, while showing us that the C program ran slower in debug mode compared to release mode. Because Assembly manually allocates the resources and C uses a compiler to allocate, hence the slower speeds. But because of the compiler and its optimizations, we noticed a bump in speed when it came to the release mode.

By Nathan Andres and Benmar Ramirez of XX22
