using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Accord.Math;
using System;
using System.Numerics;
using System.Threading.Tasks;
using Flurl.Http;

public class Diffraction : MonoBehaviour
{
    public static Diffraction Instance = null;

    public Button[] viewButtons;
    public Material ApertureMat;
    public Material ScreenMat; 
    public Transform AperatureObject;
    private Texture2D aperture;
    private Texture2D screenImage;

    public Slider radiusSlider;

    public readonly int sampling = 128;
    public readonly double screenSize = 0.1e-3;
    public double focal = 500e-3;
    public double theta = 0;
    public double lambda = 632.8e-9;
    public double diameter = 25e-6;
    public double xoffsetLens = 0;
    public double yoffsetLens = 0;
    public double xoffsetSlit = 0;
    public double yoffsetSlit = 0;

    public System.Numerics.Complex[,] aperatureInput;

    private void Start()
    {
        Instance = this;
        for (int i = 0; i < viewButtons.Length; i++)
        {
            int index = i;
            viewButtons[i].onClick.AddListener(() =>
            {
                GetComponent<CameraSwitcher>().SwitchCamera(index);
            });
        }

        aperatureInput = new System.Numerics.Complex[sampling, sampling];
        aperture = new Texture2D(sampling, sampling, TextureFormat.ARGB32, false);
        screenImage = new Texture2D(sampling, sampling, TextureFormat.ARGB32, false);
        aperture.filterMode = FilterMode.Point;
        screenImage.filterMode = FilterMode.Point;

        Color32 resetColor = new Color32(255, 255, 255, 255);
        Color32[] resetColorArray = aperture.GetPixels32();
        for (int i = 0; i < resetColorArray.Length; i++)
            resetColorArray[i] = resetColor;
        aperture.SetPixels32(resetColorArray);
        aperture.Apply();
        ApertureMat.mainTexture = aperture;

        Color32[] blackenArray = aperture.GetPixels32();
        for (int i = 0; i < blackenArray.Length; i++)
        {
            blackenArray[i] = Color.black;
        }
        screenImage.SetPixels32(blackenArray);
        screenImage.Apply();
        ScreenMat.mainTexture = screenImage;
    }

    private void ResetAperature()
    {
        for (int i = 0; i < sampling; i++)
        {
            for (int j = 0; j < sampling; j++)
            {
                aperatureInput[i, j] = 0;
                aperture.SetPixel(i, j, new Color32(255, 255, 255, 255));
            }
        }
        aperture.Apply();
    }

    public void Render()
    {
        //var delta = screenSize / sampling;
        //var k = 2 * Math.PI / lambda;
        //var tmp = Accord.Math.Vector.Interval(-sampling / 2, sampling / 2 - 1, sampling);
        //var fx = tmp.Multiply(7.32 * lambda * focal / diameter / sampling);
        //var fy = tmp.Multiply(7.32 * lambda * focal / diameter / sampling);
        //var (x1, y1) = Matrix.MeshGrid(fx, fy);
        //var result = Matrix.Zeros<Complex>(sampling, sampling);

        //List<Task<Complex[,]>> tasks = new List<Task<Complex[,]>>();
        //int size = sampling / 32;
        //for (int l = 0; l < 32; l++)
        //{
        //    int index = l;
        //    tasks.Add(Task.Run(() =>
        //    {
        //        var resulttmp = Matrix.Zeros<Complex>(sampling, sampling);
        //        int max = size * index + size;
        //        for (int i = index * size; i < max; i++)
        //        {
        //            for (int j = 0; j < sampling; j++)
        //            {
        //                var tmp1 = x1.Multiply(i - sampling / 2 * delta).Add(y1.Multiply(j - sampling / 2 * delta));
        //                var tmp2 = tmp1.MultiplyComplex(-Complex.ImaginaryOne * k * focal).Exp();
        //                resulttmp = resulttmp.Add(tmp2.Multiply(aperatureInput[i, j] * delta * delta));
        //            }
        //        }
        //        return resulttmp;
        //    }));
        //}
        //Task.WhenAll(tasks).Wait();
        //tasks.ForEach(x =>
        //{
        //    result = result.Add(x.Result);
        //});
        //result = result.Multiply(1 / lambda / focal);
        var result = $"http://localhost:5000/".PostJsonAsync(new RequestModel()
        {
            diameter = diameter,
            aperture = null,
            focal = focal,
            lambda = lambda,
            sampling = sampling,
            screenSize = screenSize,
            theta = theta,
            xoffset = xoffsetLens,
            yoffset = yoffsetLens
        }).ReceiveJson<List<List<double>>>().Result;
        
        float largest = 0;
        for (int i = 0; i < sampling - 1; i++)
        {
            for (int j = 0; j < sampling - 1; j++)
            {
                float mod = (float)result[i][j];
                if (mod > largest)
                {
                    largest = mod;
                }
            }
        }
        
        for (int i = 0; i < sampling - 1; i++)
        {
            for (int j = 0; j < sampling - 1; j++)
            {
                float mod = (float)result[i][j];
                byte whiteVal = (byte)Mathf.RoundToInt(255 * Mathf.Clamp(mod, 0, largest) / largest);
                screenImage.SetPixel(i, j, new Color32(whiteVal, whiteVal, whiteVal, 255));
            }
        }
        for (int i = 0; i < sampling - 1; i++)
        {
            for (int j = 0; j < sampling - 1; j++)
            {
                float mod = (float)result[i][j];
                byte whiteVal = (byte)Mathf.RoundToInt(255 * Mathf.Clamp(mod, 0, largest) / largest);
                screenImage.SetPixel(i, j, new Color32(whiteVal, whiteVal, whiteVal, 255));
            }
        }
        screenImage.Apply();
    }

    public void Circle()
    {
        for (int i = 0; i < sampling; i++)
        {
            for (int j = 0; j < sampling; j++)
            {
                int r = Mathf.RoundToInt((float)(diameter * sampling / screenSize / 2));
                if (Mathf.Pow((i - sampling / 2), 2) + Mathf.Pow((j - sampling / 2), 2) < r * r)
                {
                    aperatureInput[i, j] = 1;
                    aperture.SetPixel(i, j, new Color32(255, 255, 255, 0));
                }
                else
                {
                    aperatureInput[i, j] = 0;
                    aperture.SetPixel(i, j, new Color32(255, 255, 255, 255));
                }
            }
        }
        aperture.Apply();
    }
}

public class RequestModel
{
    public int sampling;
    public double screenSize;
    public double lambda;
    public System.Numerics.Complex[,] aperture;
    public double xoffset;
    public double yoffset;
    public double diameter;
    public double theta;
    public double focal;
}
public class RecieveModel
{

}