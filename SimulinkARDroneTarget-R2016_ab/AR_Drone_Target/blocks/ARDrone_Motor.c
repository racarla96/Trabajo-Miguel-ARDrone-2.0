/**
 * ARDrone_Motor.c
 *
 *    ABSTRACT:
 *      The purpose of this sfunction is to call a simple legacy
 *      function during simulation:
 *
 *         uint16 y1 = Motor_Set(uint8 u1[5])
 *
 *    Simulink version           : 8.8 (R2016b) 25-Aug-2016
 *    C source code generated on : 27-Apr-2022 17:44:28
 *
 * THIS S-FUNCTION IS GENERATED BY THE LEGACY CODE TOOL AND MAY NOT WORK IF MODIFIED
 */

/**
     %%%-MATLAB_Construction_Commands_Start
     def = legacy_code('initialize');
     def.SFunctionName = 'ARDrone_Motor';
     def.OutputFcnSpec = 'uint16 y1 = Motor_Set(uint8 u1[5])';
     def.HeaderFiles = {'motor.h'};
     def.SourceFiles = {'motor.c'};
     legacy_code('sfcn_cmex_generate', def);
     legacy_code('compile', def);
     %%%-MATLAB_Construction_Commands_End
 */

/* Must specify the S_FUNCTION_NAME as the name of the S-function */
#define S_FUNCTION_NAME  ARDrone_Motor
#define S_FUNCTION_LEVEL 2

/**
 * Need to include simstruc.h for the definition of the SimStruct and
 * its associated macro definitions.
 */
#include "simstruc.h"

/* Specific header file(s) required by the legacy code function */
#include "motor.h"

#define isDWorkNeeded(S) ((!((ssRTWGenIsCodeGen(S) || ssGetSimMode(S)==SS_SIMMODE_EXTERNAL) && isSimulationTarget==0)) || ssIsRapidAcceleratorActive(S))

/* Function: mdlInitializeSizes ===========================================
 * Abstract:
 *   The sizes information is used by Simulink to determine the S-function
 *   block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct *S)
{
    /* Number of expected parameters */
    ssSetNumSFcnParams(S, 0);


    /* Set the number of work vectors */
    if (!ssSetNumDWork(S, 0)) return;
    ssSetNumPWork(S, 0);

    /* Set the number of input ports */
    if (!ssSetNumInputPorts(S, 1)) return;

    /* Configure the input port 1 */
    ssSetInputPortDataType(S, 0, SS_UINT8);
    {
        int_T u1Width = 5;
        ssSetInputPortWidth(S, 0, u1Width);
    }
    ssSetInputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortAcceptExprInRTW(S, 0, 0);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 0, 1);

    /* Set the number of output ports */
    if (!ssSetNumOutputPorts(S, 1)) return;

    /* Configure the output port 1 */
    ssSetOutputPortDataType(S, 0, SS_UINT16);
    {
        int_T y1Width = 1;
        ssSetOutputPortWidth(S, 0, y1Width);
    }
    ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 0, 1);
    /* Register reserved identifiers to avoid name conflict */
    if (ssRTWGenIsCodeGen(S) || ssGetSimMode(S)==SS_SIMMODE_EXTERNAL) {

        /* Register reserved identifier for  */
        ssRegMdlInfo(S, "Motor_Set", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));
    } /* if */

    /* This S-function can be used in referenced model simulating in normal mode */
    ssSetModelReferenceNormalModeSupport(S, MDL_START_AND_MDL_PROCESS_PARAMS_OK);

    /* Set the number of sample time */
    ssSetNumSampleTimes(S, 1);

    /* Set the compliance with the SimState feature */
    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);

    /* Set the Simulink version this S-Function has been generated in */
    ssSetSimulinkVersionGeneratedIn(S, "8.8");

    /**
     * All options have the form SS_OPTION_<name> and are documented in
     * matlabroot/simulink/include/simstruc.h. The options should be
     * bitwise or'd together as in
     *    ssSetOptions(S, (SS_OPTION_name1 | SS_OPTION_name2))
     */
    ssSetOptions(S,
        SS_OPTION_USE_TLC_WITH_ACCELERATOR |
        SS_OPTION_CAN_BE_CALLED_CONDITIONALLY |
        SS_OPTION_EXCEPTION_FREE_CODE |
        SS_OPTION_WORKS_WITH_CODE_REUSE |
        SS_OPTION_SFUNCTION_INLINED_FOR_RTW |
        SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME
    );
}

/* Function: mdlInitializeSampleTimes =====================================
 * Abstract:
 *   This function is used to specify the sample time(s) for your
 *   S-function. You must register the same number of sample times as
 *   specified in ssSetNumSampleTimes.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);

    #if defined(ssSetModelReferenceSampleTimeDefaultInheritance)
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
    #endif
}

/* Function: mdlOutputs ===================================================
 * Abstract:
 *   In this function, you compute the outputs of your S-function
 *   block. Generally outputs are placed in the output vector(s),
 *   ssGetOutputPortSignal.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{

    /* Get access to Parameter/Input/Output/DWork data */
    uint16_T* y1 = (uint16_T*) ssGetOutputPortSignal(S, 0);
    uint8_T* u1 = (uint8_T*) ssGetInputPortSignal(S, 0);


    /* Call the legacy code function */
    *y1 = Motor_Set(u1);
}

/* Function: mdlTerminate =================================================
 * Abstract:
 *   In this function, you should perform any actions that are necessary
 *   at the termination of a simulation.
 */
static void mdlTerminate(SimStruct *S)
{
}

/* Required S-function trailer */
#ifdef    MATLAB_MEX_FILE
# include "simulink.c"
#else
# include "cg_sfun.h"
#endif

