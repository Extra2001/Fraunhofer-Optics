using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class TextSyncer : MonoBehaviour
{
    public Slider source;
    public UIBehaviour destnation;

    private InputField dest1 = null;
    private Text dest2 = null;

    // Start is called before the first frame update
    void Start()
    {
        if (destnation is InputField)
            dest1 = destnation as InputField;
        else if (destnation is Text)
            dest2 = destnation as Text;
        source.onValueChanged.AddListener(x =>
        {
            if (dest1 != null)
                dest1.text = x.ToString();
            if (dest2 != null)
                dest2.text = x.ToString();
        });
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
