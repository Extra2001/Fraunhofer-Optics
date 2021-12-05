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
    public Camera WatchCamera;
    
    public void SwitchCamera(int camera)
    {
        var position = mainCamera.transform.position;
        var rotation = mainCamera.transform.rotation;
        switch (camera)
        {
            case 0:
                position = Global.transform.position;
                rotation = Global.transform.rotation;
                break;
            case 1:
                position = Screen.transform.position;
                rotation = Screen.transform.rotation;
                break;
            case 2:
                position = Light.transform.position;
                rotation = Light.transform.rotation;
                break;
            case 3:
                position = Watch.transform.position;
                rotation = Watch.transform.rotation;
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
