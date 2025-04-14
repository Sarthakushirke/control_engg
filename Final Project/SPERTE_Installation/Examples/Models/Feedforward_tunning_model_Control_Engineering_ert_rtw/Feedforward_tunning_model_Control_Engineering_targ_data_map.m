    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
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
        ;% Auto data (Feedforward_tunning_model_Control_Engineering_P)
        ;%
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_P.SFunction_P1_Size
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_P.ref_part
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Kfc_gain
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 20;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Kfa_gain
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 21;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Kfv_gain
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 22;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Refpower_stat
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 23;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_P.MeasurementBlock_N_samples
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_P.MeasurementBlock_trigger_comman
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_P.MeasurementBlock_triggertype
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 52;
            section.data(52)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_P.SFunction_P1_Size_k
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_P.SFunction_P1
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 2;

                    ;% Feedforward_tunning_model_Control_Engineering_P.SFunction_P2_Size
                    section.data(3).logicalSrcIdx = 11;
                    section.data(3).dtTransOffset = 3;

                    ;% Feedforward_tunning_model_Control_Engineering_P.SFunction_P2
                    section.data(4).logicalSrcIdx = 12;
                    section.data(4).dtTransOffset = 5;

                    ;% Feedforward_tunning_model_Control_Engineering_P.ec_Ebox_P1_Size
                    section.data(5).logicalSrcIdx = 13;
                    section.data(5).dtTransOffset = 6;

                    ;% Feedforward_tunning_model_Control_Engineering_P.ec_Ebox_P1
                    section.data(6).logicalSrcIdx = 14;
                    section.data(6).dtTransOffset = 8;

                    ;% Feedforward_tunning_model_Control_Engineering_P.count2rad_Gain
                    section.data(7).logicalSrcIdx = 15;
                    section.data(7).dtTransOffset = 9;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Constant2_Value
                    section.data(8).logicalSrcIdx = 16;
                    section.data(8).dtTransOffset = 10;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Quantizer1_Interval
                    section.data(9).logicalSrcIdx = 17;
                    section.data(9).dtTransOffset = 11;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Gain_Gain
                    section.data(10).logicalSrcIdx = 18;
                    section.data(10).dtTransOffset = 12;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Gain1_Gain
                    section.data(11).logicalSrcIdx = 19;
                    section.data(11).dtTransOffset = 13;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctleadlag2_P1_Size
                    section.data(12).logicalSrcIdx = 20;
                    section.data(12).dtTransOffset = 14;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctleadlag2_P1
                    section.data(13).logicalSrcIdx = 21;
                    section.data(13).dtTransOffset = 16;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctleadlag2_P2_Size
                    section.data(14).logicalSrcIdx = 22;
                    section.data(14).dtTransOffset = 17;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctleadlag2_P2
                    section.data(15).logicalSrcIdx = 23;
                    section.data(15).dtTransOffset = 19;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctleadlag2_P3_Size
                    section.data(16).logicalSrcIdx = 24;
                    section.data(16).dtTransOffset = 20;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctleadlag2_P3
                    section.data(17).logicalSrcIdx = 25;
                    section.data(17).dtTransOffset = 22;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P1_Size
                    section.data(18).logicalSrcIdx = 26;
                    section.data(18).dtTransOffset = 23;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P1
                    section.data(19).logicalSrcIdx = 27;
                    section.data(19).dtTransOffset = 25;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P2_Size
                    section.data(20).logicalSrcIdx = 28;
                    section.data(20).dtTransOffset = 26;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P2
                    section.data(21).logicalSrcIdx = 29;
                    section.data(21).dtTransOffset = 28;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P3_Size
                    section.data(22).logicalSrcIdx = 30;
                    section.data(22).dtTransOffset = 29;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P3
                    section.data(23).logicalSrcIdx = 31;
                    section.data(23).dtTransOffset = 31;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P4_Size
                    section.data(24).logicalSrcIdx = 32;
                    section.data(24).dtTransOffset = 32;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P4
                    section.data(25).logicalSrcIdx = 33;
                    section.data(25).dtTransOffset = 34;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P5_Size
                    section.data(26).logicalSrcIdx = 34;
                    section.data(26).dtTransOffset = 35;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P5
                    section.data(27).logicalSrcIdx = 35;
                    section.data(27).dtTransOffset = 37;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dct1lowpass4_P1_Size
                    section.data(28).logicalSrcIdx = 36;
                    section.data(28).dtTransOffset = 38;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dct1lowpass4_P1
                    section.data(29).logicalSrcIdx = 37;
                    section.data(29).dtTransOffset = 40;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dct1lowpass4_P2_Size
                    section.data(30).logicalSrcIdx = 38;
                    section.data(30).dtTransOffset = 41;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dct1lowpass4_P2
                    section.data(31).logicalSrcIdx = 39;
                    section.data(31).dtTransOffset = 43;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P1_Size
                    section.data(32).logicalSrcIdx = 40;
                    section.data(32).dtTransOffset = 44;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P1
                    section.data(33).logicalSrcIdx = 41;
                    section.data(33).dtTransOffset = 46;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P2_Size
                    section.data(34).logicalSrcIdx = 42;
                    section.data(34).dtTransOffset = 47;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P2
                    section.data(35).logicalSrcIdx = 43;
                    section.data(35).dtTransOffset = 49;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P3_Size
                    section.data(36).logicalSrcIdx = 44;
                    section.data(36).dtTransOffset = 50;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P3
                    section.data(37).logicalSrcIdx = 45;
                    section.data(37).dtTransOffset = 52;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P4_Size
                    section.data(38).logicalSrcIdx = 46;
                    section.data(38).dtTransOffset = 53;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P4
                    section.data(39).logicalSrcIdx = 47;
                    section.data(39).dtTransOffset = 55;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P5_Size
                    section.data(40).logicalSrcIdx = 48;
                    section.data(40).dtTransOffset = 56;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P5
                    section.data(41).logicalSrcIdx = 49;
                    section.data(41).dtTransOffset = 58;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctintegrator6_P1_Size
                    section.data(42).logicalSrcIdx = 50;
                    section.data(42).dtTransOffset = 59;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctintegrator6_P1
                    section.data(43).logicalSrcIdx = 51;
                    section.data(43).dtTransOffset = 61;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctintegrator6_P2_Size
                    section.data(44).logicalSrcIdx = 52;
                    section.data(44).dtTransOffset = 62;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Dctintegrator6_P2
                    section.data(45).logicalSrcIdx = 53;
                    section.data(45).dtTransOffset = 64;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Saturation_UpperSat
                    section.data(46).logicalSrcIdx = 54;
                    section.data(46).dtTransOffset = 65;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Saturation_LowerSat
                    section.data(47).logicalSrcIdx = 55;
                    section.data(47).dtTransOffset = 66;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Saturation_UpperSat_d
                    section.data(48).logicalSrcIdx = 56;
                    section.data(48).dtTransOffset = 67;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Saturation_LowerSat_e
                    section.data(49).logicalSrcIdx = 57;
                    section.data(49).dtTransOffset = 68;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Constant1_Value
                    section.data(50).logicalSrcIdx = 58;
                    section.data(50).dtTransOffset = 69;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Constant_Value
                    section.data(51).logicalSrcIdx = 59;
                    section.data(51).dtTransOffset = 77;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Gain_Gain_g
                    section.data(52).logicalSrcIdx = 60;
                    section.data(52).dtTransOffset = 79;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_P.Selectencoder_CurrentSetting
                    section.data(1).logicalSrcIdx = 61;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
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
        nTotSects     = 1;
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
        ;% Auto data (Feedforward_tunning_model_Control_Engineering_B)
        ;%
            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_B.Startsetpoint
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_B.SFunction
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Feedforward_tunning_model_Control_Engineering_B.SFunction_b
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% Feedforward_tunning_model_Control_Engineering_B.ec_Ebox_o1
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% Feedforward_tunning_model_Control_Engineering_B.ec_Ebox_o2
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

                    ;% Feedforward_tunning_model_Control_Engineering_B.ec_Ebox_o3
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 9;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Input
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 17;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Output
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 18;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Output_g
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 19;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Error
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 20;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Gain1
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 21;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Dctleadlag2
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 22;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Dctnotch3
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 23;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Dct1lowpass4
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 24;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Dctnotch5
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 25;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Dctintegrator6
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 26;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Saturation
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 27;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Constant1
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 29;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Gain
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 37;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Downsample
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 39;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
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
        sectIdxOffset = 1;

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
        ;% Auto data (Feedforward_tunning_model_Control_Engineering_DW)
        ;%
            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Downsample_Buffer
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.fileID
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.SFunction_RWORK
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Dctleadlag2_RWORK
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 54;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Dctnotch3_RWORK
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 56;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Dct1lowpass4_RWORK
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 60;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Dctnotch5_RWORK
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 62;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Dctintegrator6_RWORK
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 66;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Velocity_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.closed_loop_error_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Output_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 10;
                    section.data(3).dtTransOffset = 2;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Reference_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 11;
                    section.data(4).dtTransOffset = 3;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Live_Scope_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 12;
                    section.data(5).dtTransOffset = 4;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.eml_openfiles
                    section.data(6).logicalSrcIdx = 13;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.sfEvent
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.NS
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.NF
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.is_active_c1_Feedforward_tunnin
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.busy
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.fileID_not_empty
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.NF_not_empty
                    section.data(3).logicalSrcIdx = 21;
                    section.data(3).dtTransOffset = 2;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.busy_not_empty
                    section.data(4).logicalSrcIdx = 22;
                    section.data(4).dtTransOffset = 3;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.NS_not_empty
                    section.data(5).logicalSrcIdx = 23;
                    section.data(5).dtTransOffset = 4;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.eml_openfiles_not_empty
                    section.data(6).logicalSrcIdx = 24;
                    section.data(6).dtTransOffset = 5;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.eml_autoflush
                    section.data(7).logicalSrcIdx = 25;
                    section.data(7).dtTransOffset = 6;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.eml_autoflush_not_empty
                    section.data(8).logicalSrcIdx = 26;
                    section.data(8).dtTransOffset = 26;

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


    targMap.checksum0 = 1762189307;
    targMap.checksum1 = 713453138;
    targMap.checksum2 = 414844363;
    targMap.checksum3 = 1039519502;

