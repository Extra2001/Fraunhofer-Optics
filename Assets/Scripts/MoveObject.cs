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
            //1. �õ��������Ļ����
            cubeScreenPos = Camera.main.WorldToScreenPoint(transform.position);

            //2. ����ƫ����
            //������ά����
            Vector3 mousePos = new Vector3(Input.mousePosition.x, Input.mousePosition.y, cubeScreenPos.z);
            //�����ά����תΪ��������
            mousePos = Camera.main.ScreenToWorldPoint(mousePos);
            offset = transform.position - mousePos;
            

            //3. ������������ƶ�
            while (Input.GetMouseButton(0))
            {
                //Ŀǰ������ά����תΪ��ά����
                Vector3 curMousePos = new Vector3(Input.mousePosition.x, Input.mousePosition.y, cubeScreenPos.z);
                //Ŀǰ�������ά����תΪ��������
                curMousePos = Camera.main.ScreenToWorldPoint(curMousePos);
                var dest = curMousePos + offset;
                var off = dest - initPos;
                if (off.z > maxOffset) dest.z = initPos.z + maxOffset;
                if (off.z < -maxOffset) dest.z = initPos.z - maxOffset;
                if (off.y > maxOffset) dest.y = initPos.y + maxOffset;
                if (off.y < -maxOffset) dest.y = initPos.y - maxOffset;

                //��������λ��
                transform.position = dest;
                yield return new WaitForFixedUpdate(); //�������Ҫ��ѭ��ִ��
            }
        }
    }
}
