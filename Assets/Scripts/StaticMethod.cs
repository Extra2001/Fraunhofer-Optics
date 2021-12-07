using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Numerics;
using Accord.Math;

public static class StaticMethod
{
    public static Complex[,] Multiply(this Complex[,] matrix, double number)
    {
        var tmp = Matrix.CreateAs(matrix);
        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                tmp[i, j] = Complex.Multiply(tmp[i, j], new Complex(number, 0));
            }
        }
        return tmp;
    }

    public static Complex[,] Multiply(this Complex[,] matrix, Complex number)
    {
        var tmp = Matrix.CreateAs(matrix);
        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                tmp[i, j] *= number;
            }
        }
        return tmp;
    }

    public static Complex[,] Exp(this Complex[,] matrix)
    {
        var tmp = Matrix.CreateAs(matrix);
        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                Complex.Exp(matrix[i, j]);
            }
        }
        return tmp;
    }

    public static Complex[,] MultiplyComplex(this double[,] matrix, Complex number)
    {
        var tmp = matrix.ToComplex();
        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                tmp[i, j] *= number;
            }
        }
        return tmp;
    }

    public static Complex[,] Add(this Complex[,] matrix, Complex[,] add)
    {
        var tmp = Matrix.CreateAs(matrix);
        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                tmp[i, j] += add[i, j];
            }
        }
        return tmp;
    }
}
