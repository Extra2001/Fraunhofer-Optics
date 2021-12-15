using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public class CameraSwitcher : MonoBehaviour
{
    public Camera mainCamera;
    public GameObject Global;
    public GameObject Screen;
    public GameObject Watch;
    public GameObject Light;
    public GameObject Focal;
    public Camera WatchCamera;
    public GameObject ScreenSettings;
    
    public void SwitchCamera(int camera)
    {
        var position = mainCamera.transform.position;
        var rotation = mainCamera.transform.rotation;
        MoveFocal.Instance.movable = false;
        MoveObject.Instance.movable = false;
        switch (camera)
        {
            case 0:
                position = Global.transform.position;
                rotation = Global.transform.rotation;
                ScreenSettings.SetActive(false);
                WatchCamera.gameObject.SetActive(false);
                break;
            case 1:
                position = Screen.transform.position;
                rotation = Screen.transform.rotation;
                ScreenSettings.SetActive(true);
                WatchCamera.gameObject.SetActive(true);
                MoveObject.Instance.movable = true;
                break;
            case 2:
                position = Light.transform.position;
                rotation = Light.transform.rotation;
                ScreenSettings.SetActive(true);
                WatchCamera.gameObject.SetActive(true);
                break;
            case 3:
                position = Watch.transform.position;
                rotation = Watch.transform.rotation;
                ScreenSettings.SetActive(false);
                WatchCamera.gameObject.SetActive(false);
                break;
            case 4:
                position = Focal.transform.position;
                rotation = Focal.transform.rotation;
                ScreenSettings.SetActive(true);
                WatchCamera.gameObject.SetActive(true);
                MoveFocal.Instance.movable = true;
                break;
        }

        mainCamera.transform.DOMove(position, .5f)
            .SetEase(Ease.OutExpo);
        mainCamera.transform.DORotate(rotation.eulerAngles, .5f)
            .SetEase(Ease.OutExpo);
    }

    public void SetPreview(bool open)
    {
        WatchCamera.gameObject.SetActive(open);
    }
}
