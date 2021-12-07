using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Accord.Math;
using System;
using System.Numerics;
using System.Threading.Tasks;
using System.Threading;
using Flurl.Http;
using circ_fraunhofer;
using MathWorks.MATLAB.NET.Arrays;

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
    public MyMatlabClass matlab = null;

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

        Task.Run(() => InitializeMatlab());

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

    private void InitializeMatlab()
    {
        matlab = new MyMatlabClass();
        matlab.circ_fraunhofer(ToMWArray(0.1e-3), ToMWArray(25e-6),
            ToMWArray(64), ToMWArray(0.5), ToMWArray(0), ToMWArray(632.8e-9), ToMWArray(0), ToMWArray(0));
        Debug.Log("Matlab引擎初始化成功");
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

    CancellationTokenSource source = null;

    public IEnumerator RenderMatlab()
    {
        double[,] result = new double[1, 1];
        source?.Cancel();
        source = new CancellationTokenSource();
        Task.Run(() =>
        {
            MyMatlabClass matlab = new MyMatlabClass();
            var result1 = matlab.circ_fraunhofer(ToMWArray(screenSize), ToMWArray(diameter), ToMWArray(sampling),
                ToMWArray(focal), ToMWArray(theta), ToMWArray(lambda), ToMWArray(xoffsetLens), ToMWArray(yoffsetLens));
            result = (double[,])result1.ToArray();
        }, source.Token);
        while (result.GetLength(0) == 1)
            yield return 1;
        float largest = 0;
        for (int i = 0; i < sampling - 1; i++)
        {
            for (int j = 0; j < sampling - 1; j++)
            {
                float mod = (float)result[i, j];
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
                float mod = (float)result[i, j];
                byte whiteVal = (byte)Mathf.RoundToInt(255 * Mathf.Clamp(mod, 0, largest) / largest);
                screenImage.SetPixel(i, j, new Color32(whiteVal, whiteVal, whiteVal, 255));
            }
        }
        for (int i = 0; i < sampling - 1; i++)
        {
            for (int j = 0; j < sampling - 1; j++)
            {
                float mod = (float)result[i, j];
                byte whiteVal = (byte)Mathf.RoundToInt(255 * Mathf.Clamp(mod, 0, largest) / largest);
                screenImage.SetPixel(i, j, new Color32(whiteVal, whiteVal, whiteVal, 255));
            }
        }
        screenImage.Apply();
    }

    public void Render()
    {
        StartCoroutine(nameof(RenderMatlab));
    }

    public static MWArray ToMWArray(double number)
    {
        double[,] vs = new double[1, 1];
        vs[0, 0] = number;
        return new MWNumericArray(vs);
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