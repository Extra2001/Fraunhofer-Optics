/*
* MATLAB Compiler: 8.0 (R2020a)
* Date: Tue Dec  7 14:12:28 2021
* Arguments:
* "-B""macro_default""-W""dotnet:circ_fraunhofer,MyMatlabClass,4.0,private,version=1.0""-T
* ""link:lib""-d""C:\Users\jingx\Projects\fraunhofer-optics\MatlabCode\circ_fraunhofer1\fo
* r_testing""-v""class{MyMatlabClass:C:\Users\jingx\Projects\fraunhofer-optics\MatlabCode\
* circ_fraunhofer.m}"
*/
using System;
using System.Reflection;
using System.IO;
using MathWorks.MATLAB.NET.Arrays;
using MathWorks.MATLAB.NET.Utility;

#if SHARED
[assembly: System.Reflection.AssemblyKeyFile(@"")]
#endif

namespace circ_fraunhoferNative
{

  /// <summary>
  /// The MyMatlabClass class provides a CLS compliant, Object (native) interface to the
  /// MATLAB functions contained in the files:
  /// <newpara></newpara>
  /// C:\Users\jingx\Projects\fraunhofer-optics\MatlabCode\circ_fraunhofer.m
  /// </summary>
  /// <remarks>
  /// @Version 1.0
  /// </remarks>
  public class MyMatlabClass : IDisposable
  {
    #region Constructors

    /// <summary internal= "true">
    /// The static constructor instantiates and initializes the MATLAB Runtime instance.
    /// </summary>
    static MyMatlabClass()
    {
      if (MWMCR.MCRAppInitialized)
      {
        try
        {
          Assembly assembly= Assembly.GetExecutingAssembly();

          string ctfFilePath= assembly.Location;

		  int lastDelimiter = ctfFilePath.LastIndexOf(@"/");

	      if (lastDelimiter == -1)
		  {
		    lastDelimiter = ctfFilePath.LastIndexOf(@"\");
		  }

          ctfFilePath= ctfFilePath.Remove(lastDelimiter, (ctfFilePath.Length - lastDelimiter));

          string ctfFileName = "circ_fraunhofer.ctf";

          Stream embeddedCtfStream = null;

          String[] resourceStrings = assembly.GetManifestResourceNames();

          foreach (String name in resourceStrings)
          {
            if (name.Contains(ctfFileName))
            {
              embeddedCtfStream = assembly.GetManifestResourceStream(name);
              break;
            }
          }
          mcr= new MWMCR("",
                         ctfFilePath, embeddedCtfStream, true);
        }
        catch(Exception ex)
        {
          ex_ = new Exception("MWArray assembly failed to be initialized", ex);
        }
      }
      else
      {
        ex_ = new ApplicationException("MWArray assembly could not be initialized");
      }
    }


    /// <summary>
    /// Constructs a new instance of the MyMatlabClass class.
    /// </summary>
    public MyMatlabClass()
    {
      if(ex_ != null)
      {
        throw ex_;
      }
    }


    #endregion Constructors

    #region Finalize

    /// <summary internal= "true">
    /// Class destructor called by the CLR garbage collector.
    /// </summary>
    ~MyMatlabClass()
    {
      Dispose(false);
    }


    /// <summary>
    /// Frees the native resources associated with this object
    /// </summary>
    public void Dispose()
    {
      Dispose(true);

      GC.SuppressFinalize(this);
    }


    /// <summary internal= "true">
    /// Internal dispose function
    /// </summary>
    protected virtual void Dispose(bool disposing)
    {
      if (!disposed)
      {
        disposed= true;

        if (disposing)
        {
          // Free managed resources;
        }

        // Free native resources
      }
    }


    #endregion Finalize

    #region Methods

    /// <summary>
    /// Provides a single output, 0-input Objectinterface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <returns>An Object containing the first output argument.</returns>
    ///
    public Object circ_fraunhofer()
    {
      return mcr.EvaluateFunction("circ_fraunhofer", new Object[]{});
    }


    /// <summary>
    /// Provides a single output, 1-input Objectinterface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="L">Input argument #1</param>
    /// <returns>An Object containing the first output argument.</returns>
    ///
    public Object circ_fraunhofer(Object L)
    {
      return mcr.EvaluateFunction("circ_fraunhofer", L);
    }


    /// <summary>
    /// Provides a single output, 2-input Objectinterface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <returns>An Object containing the first output argument.</returns>
    ///
    public Object circ_fraunhofer(Object L, Object D)
    {
      return mcr.EvaluateFunction("circ_fraunhofer", L, D);
    }


    /// <summary>
    /// Provides a single output, 3-input Objectinterface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <param name="N">Input argument #3</param>
    /// <returns>An Object containing the first output argument.</returns>
    ///
    public Object circ_fraunhofer(Object L, Object D, Object N)
    {
      return mcr.EvaluateFunction("circ_fraunhofer", L, D, N);
    }


    /// <summary>
    /// Provides a single output, 4-input Objectinterface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <param name="N">Input argument #3</param>
    /// <param name="f">Input argument #4</param>
    /// <returns>An Object containing the first output argument.</returns>
    ///
    public Object circ_fraunhofer(Object L, Object D, Object N, Object f)
    {
      return mcr.EvaluateFunction("circ_fraunhofer", L, D, N, f);
    }


    /// <summary>
    /// Provides a single output, 5-input Objectinterface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <param name="N">Input argument #3</param>
    /// <param name="f">Input argument #4</param>
    /// <param name="sita">Input argument #5</param>
    /// <returns>An Object containing the first output argument.</returns>
    ///
    public Object circ_fraunhofer(Object L, Object D, Object N, Object f, Object sita)
    {
      return mcr.EvaluateFunction("circ_fraunhofer", L, D, N, f, sita);
    }


    /// <summary>
    /// Provides a single output, 6-input Objectinterface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <param name="N">Input argument #3</param>
    /// <param name="f">Input argument #4</param>
    /// <param name="sita">Input argument #5</param>
    /// <param name="lambda">Input argument #6</param>
    /// <returns>An Object containing the first output argument.</returns>
    ///
    public Object circ_fraunhofer(Object L, Object D, Object N, Object f, Object sita, 
                            Object lambda)
    {
      return mcr.EvaluateFunction("circ_fraunhofer", L, D, N, f, sita, lambda);
    }


    /// <summary>
    /// Provides a single output, 7-input Objectinterface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <param name="N">Input argument #3</param>
    /// <param name="f">Input argument #4</param>
    /// <param name="sita">Input argument #5</param>
    /// <param name="lambda">Input argument #6</param>
    /// <param name="xd">Input argument #7</param>
    /// <returns>An Object containing the first output argument.</returns>
    ///
    public Object circ_fraunhofer(Object L, Object D, Object N, Object f, Object sita, 
                            Object lambda, Object xd)
    {
      return mcr.EvaluateFunction("circ_fraunhofer", L, D, N, f, sita, lambda, xd);
    }


    /// <summary>
    /// Provides a single output, 8-input Objectinterface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <param name="N">Input argument #3</param>
    /// <param name="f">Input argument #4</param>
    /// <param name="sita">Input argument #5</param>
    /// <param name="lambda">Input argument #6</param>
    /// <param name="xd">Input argument #7</param>
    /// <param name="yd">Input argument #8</param>
    /// <returns>An Object containing the first output argument.</returns>
    ///
    public Object circ_fraunhofer(Object L, Object D, Object N, Object f, Object sita, 
                            Object lambda, Object xd, Object yd)
    {
      return mcr.EvaluateFunction("circ_fraunhofer", L, D, N, f, sita, lambda, xd, yd);
    }


    /// <summary>
    /// Provides the standard 0-input Object interface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="numArgsOut">The number of output arguments to return.</param>
    /// <returns>An Array of length "numArgsOut" containing the output
    /// arguments.</returns>
    ///
    public Object[] circ_fraunhofer(int numArgsOut)
    {
      return mcr.EvaluateFunction(numArgsOut, "circ_fraunhofer", new Object[]{});
    }


    /// <summary>
    /// Provides the standard 1-input Object interface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="numArgsOut">The number of output arguments to return.</param>
    /// <param name="L">Input argument #1</param>
    /// <returns>An Array of length "numArgsOut" containing the output
    /// arguments.</returns>
    ///
    public Object[] circ_fraunhofer(int numArgsOut, Object L)
    {
      return mcr.EvaluateFunction(numArgsOut, "circ_fraunhofer", L);
    }


    /// <summary>
    /// Provides the standard 2-input Object interface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="numArgsOut">The number of output arguments to return.</param>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <returns>An Array of length "numArgsOut" containing the output
    /// arguments.</returns>
    ///
    public Object[] circ_fraunhofer(int numArgsOut, Object L, Object D)
    {
      return mcr.EvaluateFunction(numArgsOut, "circ_fraunhofer", L, D);
    }


    /// <summary>
    /// Provides the standard 3-input Object interface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="numArgsOut">The number of output arguments to return.</param>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <param name="N">Input argument #3</param>
    /// <returns>An Array of length "numArgsOut" containing the output
    /// arguments.</returns>
    ///
    public Object[] circ_fraunhofer(int numArgsOut, Object L, Object D, Object N)
    {
      return mcr.EvaluateFunction(numArgsOut, "circ_fraunhofer", L, D, N);
    }


    /// <summary>
    /// Provides the standard 4-input Object interface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="numArgsOut">The number of output arguments to return.</param>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <param name="N">Input argument #3</param>
    /// <param name="f">Input argument #4</param>
    /// <returns>An Array of length "numArgsOut" containing the output
    /// arguments.</returns>
    ///
    public Object[] circ_fraunhofer(int numArgsOut, Object L, Object D, Object N, Object 
                              f)
    {
      return mcr.EvaluateFunction(numArgsOut, "circ_fraunhofer", L, D, N, f);
    }


    /// <summary>
    /// Provides the standard 5-input Object interface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="numArgsOut">The number of output arguments to return.</param>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <param name="N">Input argument #3</param>
    /// <param name="f">Input argument #4</param>
    /// <param name="sita">Input argument #5</param>
    /// <returns>An Array of length "numArgsOut" containing the output
    /// arguments.</returns>
    ///
    public Object[] circ_fraunhofer(int numArgsOut, Object L, Object D, Object N, Object 
                              f, Object sita)
    {
      return mcr.EvaluateFunction(numArgsOut, "circ_fraunhofer", L, D, N, f, sita);
    }


    /// <summary>
    /// Provides the standard 6-input Object interface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="numArgsOut">The number of output arguments to return.</param>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <param name="N">Input argument #3</param>
    /// <param name="f">Input argument #4</param>
    /// <param name="sita">Input argument #5</param>
    /// <param name="lambda">Input argument #6</param>
    /// <returns>An Array of length "numArgsOut" containing the output
    /// arguments.</returns>
    ///
    public Object[] circ_fraunhofer(int numArgsOut, Object L, Object D, Object N, Object 
                              f, Object sita, Object lambda)
    {
      return mcr.EvaluateFunction(numArgsOut, "circ_fraunhofer", L, D, N, f, sita, lambda);
    }


    /// <summary>
    /// Provides the standard 7-input Object interface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="numArgsOut">The number of output arguments to return.</param>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <param name="N">Input argument #3</param>
    /// <param name="f">Input argument #4</param>
    /// <param name="sita">Input argument #5</param>
    /// <param name="lambda">Input argument #6</param>
    /// <param name="xd">Input argument #7</param>
    /// <returns>An Array of length "numArgsOut" containing the output
    /// arguments.</returns>
    ///
    public Object[] circ_fraunhofer(int numArgsOut, Object L, Object D, Object N, Object 
                              f, Object sita, Object lambda, Object xd)
    {
      return mcr.EvaluateFunction(numArgsOut, "circ_fraunhofer", L, D, N, f, sita, lambda, xd);
    }


    /// <summary>
    /// Provides the standard 8-input Object interface to the circ_fraunhofer MATLAB
    /// function.
    /// </summary>
    /// <remarks>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="numArgsOut">The number of output arguments to return.</param>
    /// <param name="L">Input argument #1</param>
    /// <param name="D">Input argument #2</param>
    /// <param name="N">Input argument #3</param>
    /// <param name="f">Input argument #4</param>
    /// <param name="sita">Input argument #5</param>
    /// <param name="lambda">Input argument #6</param>
    /// <param name="xd">Input argument #7</param>
    /// <param name="yd">Input argument #8</param>
    /// <returns>An Array of length "numArgsOut" containing the output
    /// arguments.</returns>
    ///
    public Object[] circ_fraunhofer(int numArgsOut, Object L, Object D, Object N, Object 
                              f, Object sita, Object lambda, Object xd, Object yd)
    {
      return mcr.EvaluateFunction(numArgsOut, "circ_fraunhofer", L, D, N, f, sita, lambda, xd, yd);
    }


    /// <summary>
    /// Provides an interface for the circ_fraunhofer function in which the input and
    /// output
    /// arguments are specified as an array of Objects.
    /// </summary>
    /// <remarks>
    /// This method will allocate and return by reference the output argument
    /// array.<newpara></newpara>
    /// M-Documentation:
    /// imagesc(aperture)
    /// </remarks>
    /// <param name="numArgsOut">The number of output arguments to return</param>
    /// <param name= "argsOut">Array of Object output arguments</param>
    /// <param name= "argsIn">Array of Object input arguments</param>
    /// <param name= "varArgsIn">Array of Object representing variable input
    /// arguments</param>
    ///
    [MATLABSignature("circ_fraunhofer", 8, 1, 0)]
    protected void circ_fraunhofer(int numArgsOut, ref Object[] argsOut, Object[] argsIn, params Object[] varArgsIn)
    {
        mcr.EvaluateFunctionForTypeSafeCall("circ_fraunhofer", numArgsOut, ref argsOut, argsIn, varArgsIn);
    }

    /// <summary>
    /// This method will cause a MATLAB figure window to behave as a modal dialog box.
    /// The method will not return until all the figure windows associated with this
    /// component have been closed.
    /// </summary>
    /// <remarks>
    /// An application should only call this method when required to keep the
    /// MATLAB figure window from disappearing.  Other techniques, such as calling
    /// Console.ReadLine() from the application should be considered where
    /// possible.</remarks>
    ///
    public void WaitForFiguresToDie()
    {
      mcr.WaitForFiguresToDie();
    }



    #endregion Methods

    #region Class Members

    private static MWMCR mcr= null;

    private static Exception ex_= null;

    private bool disposed= false;

    #endregion Class Members
  }
}
