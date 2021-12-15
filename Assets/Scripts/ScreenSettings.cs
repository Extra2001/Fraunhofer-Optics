using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ScreenSettings : MonoBehaviour
{
    public static ScreenSettings Instance = null;

    public Button[] buttons;
    public GameObject[] gameObjects;
    public Slider slider;
    public Slider lightSlider;
    public Toggle linearLight;
    public Slider lambdaSlider;
    public Slider focalSlider;
    public Text xoffset;
    public Text yoffset;

    public Transform lightSource;
    // Start is called before the first frame update
    void Start()
    {
        Instance = this;
        for (int i = 0; i < buttons.Length; i++)
        {
            int index = i;
            buttons[i].onClick.AddListener(() =>
            {
                switch (index)
                {
                    case 0:
                        Diffraction.Instance.diameter = Mathf.Round(slider.value) * 1e-6;
                        slider.value = 25;
                        lightSlider.value = 0;
                        lambdaSlider.value = 632.8f;
                        focalSlider.value = 50;
                        MoveFocal.Instance.ResetPosition();
                        MoveObject.Instance.ResetPosition();
                        Diffraction.Instance.Circle();
                        Diffraction.Instance.Render();
                        break;
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                }
                foreach (var item in gameObjects)
                    item.SetActive(false);
                gameObjects[index].SetActive(true);
            });
        }

        slider.onValueChanged.AddListener(x =>
        {
            Diffraction.Instance.diameter = Mathf.Round(slider.value) * 1e-6;
            Diffraction.Instance.Circle();
            Diffraction.Instance.Render();
        });
        lightSlider.onValueChanged.AddListener(x =>
        {
            Diffraction.Instance.theta = lightSlider.value;
            var rotation = lightSource.localRotation.eulerAngles;
            rotation.z = -x;
            lightSource.localRotation = Quaternion.Euler(rotation);
            Diffraction.Instance.Circle();
            Diffraction.Instance.Render();
        });
        linearLight.onValueChanged.AddListener(x =>
        {
            Diffraction.Instance.linearLight = x;
            Diffraction.Instance.Render();
        });
        lambdaSlider.onValueChanged.AddListener(x =>
        {
            Diffraction.Instance.lambda = lambdaSlider.value * 1e-9;
            Diffraction.Instance.Circle();
            Diffraction.Instance.Render();
        });
        focalSlider.onValueChanged.AddListener(x =>
        {
            Diffraction.Instance.focal = focalSlider.value * 1e-3;
            Diffraction.Instance.Render();
        });
    }
}
