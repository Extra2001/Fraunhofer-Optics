using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ScreenSettings : MonoBehaviour
{
    public Button[] buttons;
    public GameObject[] gameObjects;
    public Slider slider;
    // Start is called before the first frame update
    void Start()
    {
        for (int i = 0; i < buttons.Length; i++)
        {
            int index = i;
            buttons[i].onClick.AddListener(() =>
            {
                switch (index)
                {
                    case 0:
                        Diffraction.Instance.diameter = Mathf.Round(slider.value) * 1e-6;
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
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
