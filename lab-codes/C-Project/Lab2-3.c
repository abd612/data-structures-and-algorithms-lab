#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define QuadraticAlgorithm

#ifdef CubicAlgorithm

int MaxSubsequenceSum (const int A[], int N)
{
    int ThisSum, MaxSum, i, j, k;
    
    MaxSum = 0;
    
    for (i = 0; i < N; i++)
        for (j = i; j < N; j++)
        {
            ThisSum = 0;
            
            for (k = i; k <= j; k++)
                ThisSum += A[k];
                
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
        return MaxSum;
}

#endif

#ifdef QuadraticAlgorithm

int MaxSubsequenceSum (const int A[], int N)
{
    int ThisSum, MaxSum, i, j;
    
    MaxSum = 0;
    
    for (i = 0; i < N; i++)
    {
        ThisSum = 0;
            
        for (j = i; j < N; j++)
        {
            ThisSum += A[j];
                
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        }
    }
        return MaxSum;
}

#endif

#ifdef NlogNAlgorithm

static int Max3 (int A, int B, int C)
{
    return A > B ? A > C? A : C : B > C ? B : C;
}

static int MaxSubSum (const int A[], int Left, int Right)
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;
    
    if (Left == Right)
    {
        if (A[Left] > 0)
            return A[Left];
    }
    else
        return 0;
    
    Center = (Left + Right) / 2;
    MaxLeftSum = MaxSubSum (A, Left, Center);
    MaxRightSum = MaxSubSum (A, Center + 1, Right);
    
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    
    for (i = Center; i >= Left; i--)
    {
        LeftBorderSum += A[i];
        
        if (LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }
    
    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    
    for (i = Center + 1; i <= Right; i++)
    {
        RightBorderSum += A[i];
        
        if (RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }
    
    return Max3 (MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubsequenceSum (const int A[], int N)
{
    return MaxSubSum (A, 0, N - 1);
}

#endif

#ifdef LinearAlgorithm

int MaxSubsequenceSum (const int A[], int N)
{
    int ThisSum, MaxSum, j;
    
    ThisSum = MaxSum = 0;
    
    for (j = 0; j < N; j++)
    {
        ThisSum += A[j];
        
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    
    return MaxSum;
}

#endif

int main (void)
{
    LARGE_INTEGER start_time, end_time, elapsed_time, run_time, frequency;
    
    int i, N = 5000 + 166 * 10;
    int A[N];
    
    for (i = 0; i < N; i++)
        A[i] = rand() % 10;
    
    QueryPerformanceFrequency (&frequency);
    QueryPerformanceCounter (&start_time);
    
    printf ("Maximum sum is: %d\n", MaxSubsequenceSum(A, N));
    
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time.QuadPart = elapsed_time.QuadPart * 10000000 / frequency.QuadPart;
    
    printf ("The running time of the codex is: %I64d\n", run_time);
    
    return 0;
}