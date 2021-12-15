using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveObject : MonoBehaviour
{
    public static MoveObject Instance;
    public bool movable = false;
    public float maxOffset = 0.3f;
    Vector3 cubeScreenPos;
    Vector3 offset;
    Vector3 initPos;

    void Start()
    {
        Instance = this;
        initPos = transform.position;
        StartCoroutine(OnMouseDown());
    }

    public void ResetPosition()
    {
        transform.position = initPos;
    }

    IEnumerator OnMouseDown()
    {
        if (movable)
        {
            //1. 得到物体的屏幕坐标
            cubeScreenPos = Camera.main.WorldToScreenPoint(transform.position);

            //2. 计算偏移量
            //鼠标的三维坐标
            Vector3 mousePos = new Vector3(Input.mousePosition.x, Input.mousePosition.y, cubeScreenPos.z);
            //鼠标三维坐标转为世界坐标
            mousePos = Camera.main.ScreenToWorldPoint(mousePos);
            offset = transform.position - mousePos;
            

            //3. 物体随着鼠标移动
            while (Input.GetMouseButton(0))
            {
                //目前的鼠标二维坐标转为三维坐标
                Vector3 curMousePos = new Vector3(Input.mousePosition.x, Input.mousePosition.y, cubeScreenPos.z);
                //目前的鼠标三维坐标转为世界坐标
                curMousePos = Camera.main.ScreenToWorldPoint(curMousePos);
                var dest = curMousePos + offset;
                var off = dest - initPos;
                if (off.z > maxOffset) dest.z = initPos.z + maxOffset;
                if (off.z < -maxOffset) dest.z = initPos.z - maxOffset;
                if (off.y > maxOffset) dest.y = initPos.y + maxOffset;
                if (off.y < -maxOffset) dest.y = initPos.y - maxOffset;

                //物体世界位置
                transform.position = dest;
                yield return new WaitForFixedUpdate(); //这个很重要，循环执行
            }
        }
    }
}
