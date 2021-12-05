using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using MathNet.Numerics;

public class Diffraction : MonoBehaviour
{
    public Button[] viewButtons;
    public Material ApertureMat;
    public Material ScreenMat; 
    public Transform AperatureObject;
    private Texture2D aperture;
    private Texture2D screenImage;

    public Slider radiusSlider;

    readonly int aperatureSize = 128;
    public System.Numerics.Complex[,] aperatureInput;

    private void Start()
    {
        for (int i = 0; i < viewButtons.Length; i++)
        {
            int index = i;
            viewButtons[i].onClick.AddListener(() =>
            {
                GetComponent<CameraSwitcher>().SwitchCamera(index);
            });
        }

        aperatureInput = new System.Numerics.Complex[aperatureSize, aperatureSize];
        aperture = new Texture2D(aperatureSize, aperatureSize, TextureFormat.ARGB32, false);
        screenImage = new Texture2D(aperatureSize, aperatureSize, TextureFormat.ARGB32, false);
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
        for (int i = 0; i < aperatureSize; i++)
        {
            for (int j = 0; j < aperatureSize; j++)
            {
                aperatureInput[i, j] = 0;
                aperture.SetPixel(i, j, new Color32(255, 255, 255, 255));
            }
        }
        aperture.Apply();
    }

    private void Render()
    {
        
    }

    public void Pinhole()
    {
        for (int i = 0; i < aperatureSize; i++)
        {
            for (int j = 0; j < aperatureSize; j++)
            {
                if (Mathf.Pow((i - aperatureSize / 2), 2) + Mathf.Pow((j - aperatureSize / 2), 2) < 25)
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
