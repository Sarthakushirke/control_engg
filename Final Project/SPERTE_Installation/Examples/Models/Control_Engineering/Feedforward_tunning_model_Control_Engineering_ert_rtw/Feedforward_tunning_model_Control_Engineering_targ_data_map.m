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
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_P.SFunction_P1_Size
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_P.ref_part
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Refpower_stat
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_P.MeasurementBlock_N_samples
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_P.MeasurementBlock_trigger_comman
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_P.MeasurementBlock_triggertype
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 17;
            section.data(17)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_P.Gain_Gain
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_P.SFunction_P1_Size_k
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% Feedforward_tunning_model_Control_Engineering_P.SFunction_P1
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 3;

                    ;% Feedforward_tunning_model_Control_Engineering_P.SFunction_P2_Size
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 4;

                    ;% Feedforward_tunning_model_Control_Engineering_P.SFunction_P2
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 6;

                    ;% Feedforward_tunning_model_Control_Engineering_P.ec_Ebox_P1_Size
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 7;

                    ;% Feedforward_tunning_model_Control_Engineering_P.ec_Ebox_P1
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 9;

                    ;% Feedforward_tunning_model_Control_Engineering_P.count2rad_Gain
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 10;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Constant2_Value
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 11;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Quantizer1_Interval
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 12;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Saturation_UpperSat
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 13;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Saturation_LowerSat
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 14;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Saturation_UpperSat_d
                    section.data(13).logicalSrcIdx = 18;
                    section.data(13).dtTransOffset = 15;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Saturation_LowerSat_e
                    section.data(14).logicalSrcIdx = 19;
                    section.data(14).dtTransOffset = 16;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Constant1_Value
                    section.data(15).logicalSrcIdx = 20;
                    section.data(15).dtTransOffset = 17;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Constant_Value
                    section.data(16).logicalSrcIdx = 21;
                    section.data(16).dtTransOffset = 25;

                    ;% Feedforward_tunning_model_Control_Engineering_P.Gain_Gain_g
                    section.data(17).logicalSrcIdx = 22;
                    section.data(17).dtTransOffset = 27;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_P.Selectencoder_CurrentSetting
                    section.data(1).logicalSrcIdx = 23;
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
            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

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

                    ;% Feedforward_tunning_model_Control_Engineering_B.Error
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 19;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Saturation
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 20;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Constant1
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 22;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Gain
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 30;

                    ;% Feedforward_tunning_model_Control_Engineering_B.Downsample
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 32;

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
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Downsample_Buffer
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.fileID
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.SFunction_RWORK
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Velocity_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.closed_loop_error_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Output_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Reference_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.Live_Scope_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 4;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.eml_openfiles
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.sfEvent
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.NS
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.NF
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.is_active_c1_Feedforward_tunnin
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.busy
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Feedforward_tunning_model_Control_Engineering_DW.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.fileID_not_empty
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 1;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.NF_not_empty
                    section.data(3).logicalSrcIdx = 16;
                    section.data(3).dtTransOffset = 2;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.busy_not_empty
                    section.data(4).logicalSrcIdx = 17;
                    section.data(4).dtTransOffset = 3;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.NS_not_empty
                    section.data(5).logicalSrcIdx = 18;
                    section.data(5).dtTransOffset = 4;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.eml_openfiles_not_empty
                    section.data(6).logicalSrcIdx = 19;
                    section.data(6).dtTransOffset = 5;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.eml_autoflush
                    section.data(7).logicalSrcIdx = 20;
                    section.data(7).dtTransOffset = 6;

                    ;% Feedforward_tunning_model_Control_Engineering_DW.eml_autoflush_not_empty
                    section.data(8).logicalSrcIdx = 21;
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


    targMap.checksum0 = 3303574164;
    targMap.checksum1 = 341010506;
    targMap.checksum2 = 640023271;
    targMap.checksum3 = 988254784;

