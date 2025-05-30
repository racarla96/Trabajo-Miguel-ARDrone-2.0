  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Free_Flight_PID_RPY_Sen_P)
    ;%
      section.nData     = 73;
      section.data(73)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_P.accelerometerXyzGains
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Free_Flight_PID_RPY_Sen_P.accelerometerXyzOffsets
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Free_Flight_PID_RPY_Sen_P.gyroXyzOffsets
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Free_Flight_PID_RPY_Sen_P.PIDRP_D
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 9;
	
	  ;% Free_Flight_PID_RPY_Sen_P.PIDRP_I
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 10;
	
	  ;% Free_Flight_PID_RPY_Sen_P.PIDRP_LowerSaturationLimit
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 11;
	
	  ;% Free_Flight_PID_RPY_Sen_P.PIDRP_N
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% Free_Flight_PID_RPY_Sen_P.PIDRP_P
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 13;
	
	  ;% Free_Flight_PID_RPY_Sen_P.PIDRP_UpperSaturationLimit
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 14;
	
	  ;% Free_Flight_PID_RPY_Sen_P.NormalizeVector_maxzero
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 15;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Cero_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 16;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Uno_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 17;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Kd_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Kp_Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Constant_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 20;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Empuje_Value
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 21;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Roll_sin_Amp
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 22;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Roll_sin_Bias
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 23;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Roll_sin_Freq
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 24;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Roll_sin_Hsin
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 25;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Roll_sin_HCos
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 26;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Roll_sin_PSin
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 27;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Roll_sin_PCos
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 28;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Yaw_Value
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 29;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Switch_Threshold
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 30;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Pitch_sin_Amp
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 31;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Pitch_sin_Bias
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 32;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Pitch_sin_Freq
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 33;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Pitch_sin_Hsin
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 34;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Pitch_sin_HCos
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 35;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Pitch_sin_PSin
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 36;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Pitch_sin_PCos
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 37;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Switch1_Threshold
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 38;
	
	  ;% Free_Flight_PID_RPY_Sen_P.UnitDelay1_InitialCondition
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 39;
	
	  ;% Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 41;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Gain_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 45;
	
	  ;% Free_Flight_PID_RPY_Sen_P.InvertAxesDefinition_Gain
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 48;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Gain1_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 49;
	
	  ;% Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition_a
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 50;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Gain_Gain_h
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 51;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Gain4_Gain
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 52;
	
	  ;% Free_Flight_PID_RPY_Sen_P.UnitDelay1_InitialCondition_f
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 53;
	
	  ;% Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition_k
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 55;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Gain5_Gain
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 59;
	
	  ;% Free_Flight_PID_RPY_Sen_P.DiscreteTimeIntegrator1_gainval
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 60;
	
	  ;% Free_Flight_PID_RPY_Sen_P.DiscreteTimeIntegrator1_IC
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 61;
	
	  ;% Free_Flight_PID_RPY_Sen_P.ChangeSign_Gain
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 62;
	
	  ;% Free_Flight_PID_RPY_Sen_P.sat_err_UpperSat
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 63;
	
	  ;% Free_Flight_PID_RPY_Sen_P.sat_err_LowerSat
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 65;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Ganancia_Gain
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 67;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Filtro_vel_NumCoef
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 69;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Filtro_vel_DenCoef
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 70;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Filtro_vel_InitialStates
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 72;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Integrator_gainval
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 73;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Integrator_IC
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 74;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Filter_gainval
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 75;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Filter_IC
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 76;
	
	  ;% Free_Flight_PID_RPY_Sen_P.sat_err1_UpperSat
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 77;
	
	  ;% Free_Flight_PID_RPY_Sen_P.sat_err1_LowerSat
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 78;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Ki_gainval
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 79;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Ki_IC
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 80;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Ki_UpperSat
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 81;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Ki_LowerSat
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 82;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Switch_Threshold_h
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 83;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Reloj_Amp
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 84;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Reloj_Period
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 85;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Reloj_Duty
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 86;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Reloj_PhaseDelay
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 87;
	
	  ;% Free_Flight_PID_RPY_Sen_P.ZeroGain_Gain
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 88;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Constant_Value_b
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 89;
	
	  ;% Free_Flight_PID_RPY_Sen_P.BlockingTimeus_Value
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 90;
	
	  ;% Free_Flight_PID_RPY_Sen_P.UnitDelay2_InitialCondition
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 91;
	
	  ;% Free_Flight_PID_RPY_Sen_P.UnitDelay1_InitialCondition_d
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 95;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_P.Port_Value
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_P.Paro_Value
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Free_Flight_PID_RPY_Sen_P.minThrottle_Value
	  section.data(2).logicalSrcIdx = 75;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Free_Flight_PID_RPY_Sen_P.MotorMixing_Gain
	  section.data(3).logicalSrcIdx = 76;
	  section.data(3).dtTransOffset = 5;
	
	  ;% Free_Flight_PID_RPY_Sen_P.maxThrottle_Value
	  section.data(4).logicalSrcIdx = 77;
	  section.data(4).dtTransOffset = 21;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Saturation_UpperSat
	  section.data(5).logicalSrcIdx = 78;
	  section.data(5).dtTransOffset = 22;
	
	  ;% Free_Flight_PID_RPY_Sen_P.Saturation_LowerSat
	  section.data(6).logicalSrcIdx = 79;
	  section.data(6).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_P.BitwiseOperator_BitMask
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Free_Flight_PID_RPY_Sen_P.BitwiseOperator1_BitMask
	  section.data(2).logicalSrcIdx = 81;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_P.Gain_Gain_f
	  section.data(1).logicalSrcIdx = 82;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_P.Conm_CurrentSetting
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Free_Flight_PID_RPY_Sen_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtWork_refInport1
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_B.Gain
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Free_Flight_PID_RPY_Sen_B.ChangeSign
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Free_Flight_PID_RPY_Sen_B.ByteUnpack
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtUDPSend2Inport1
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_B.Empuje
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Free_Flight_PID_RPY_Sen_B.Yaw
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Free_Flight_PID_RPY_Sen_B.Switch
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Free_Flight_PID_RPY_Sen_B.Switch1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_B.SFunction_o1
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_B.Switch_d
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_B.ARDrone_Motor
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_B.SFunction_o2
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 7;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Free_Flight_PID_RPY_Sen_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_DW.storedGoodPacket
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_e
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE_k
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 9;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 11;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.DiscreteTimeIntegrator1_DSTATE
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 15;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.Filtro_vel_states
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 16;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.Integrator_DSTATE
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 19;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.Filter_DSTATE
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 21;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.Ki_DSTATE
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 23;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 24;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE_h
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 28;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.lastSin
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 30;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.lastCos
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 31;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.lastSin_c
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 32;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.lastCos_b
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 33;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.validHeight
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 34;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.UDPSend2_NetworkLib
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_DW.Work_ang_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.Work_pwm_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.Work_ref_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.Work_vel_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_DW.systemEnable
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.systemEnable_d
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.clockTickCounter
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_DW.storedBadChecksum
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_DW.Integrator_PrevResetState
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.Filter_PrevResetState
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.Ki_PrevResetState
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.Medidas_SubsysRanBC
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Free_Flight_PID_RPY_Sen_DW.storedGoodPacket_not_empty
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Free_Flight_PID_RPY_Sen_DW.storedBadChecksum_not_empty
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1929515908;
  targMap.checksum1 = 3259548639;
  targMap.checksum2 = 2351579559;
  targMap.checksum3 = 802697372;

