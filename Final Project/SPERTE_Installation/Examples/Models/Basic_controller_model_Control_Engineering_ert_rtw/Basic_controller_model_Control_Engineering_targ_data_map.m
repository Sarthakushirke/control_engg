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
        ;% Auto data (Basic_controller_model_Control_Engineering_P)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_P.SFunction_P1_Size
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Basic_controller_model_Control_Engineering_P.ref_part
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% Basic_controller_model_Control_Engineering_P.Refpower_stat
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_P.MeasurementBlock_N_samples
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_P.MeasurementBlock_trigger_comman
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% Basic_controller_model_Control_Engineering_P.MeasurementBlock_triggertype
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 38;
            section.data(38)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_P.SFunction_P1_Size_k
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% Basic_controller_model_Control_Engineering_P.SFunction_P1
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 2;

                    ;% Basic_controller_model_Control_Engineering_P.SFunction_P2_Size
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 3;

                    ;% Basic_controller_model_Control_Engineering_P.SFunction_P2
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 5;

                    ;% Basic_controller_model_Control_Engineering_P.ec_Ebox_P1_Size
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 6;

                    ;% Basic_controller_model_Control_Engineering_P.ec_Ebox_P1
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 8;

                    ;% Basic_controller_model_Control_Engineering_P.Quantizer1_Interval
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 9;

                    ;% Basic_controller_model_Control_Engineering_P.count2rad_Gain
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 10;

                    ;% Basic_controller_model_Control_Engineering_P.Gain_Gain
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 11;

                    ;% Basic_controller_model_Control_Engineering_P.Constant2_Value
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 12;

                    ;% Basic_controller_model_Control_Engineering_P.Gain1_Gain
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 13;

                    ;% Basic_controller_model_Control_Engineering_P.Dctleadlag2_P1_Size
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 14;

                    ;% Basic_controller_model_Control_Engineering_P.Dctleadlag2_P1
                    section.data(13).logicalSrcIdx = 18;
                    section.data(13).dtTransOffset = 16;

                    ;% Basic_controller_model_Control_Engineering_P.Dctleadlag2_P2_Size
                    section.data(14).logicalSrcIdx = 19;
                    section.data(14).dtTransOffset = 17;

                    ;% Basic_controller_model_Control_Engineering_P.Dctleadlag2_P2
                    section.data(15).logicalSrcIdx = 20;
                    section.data(15).dtTransOffset = 19;

                    ;% Basic_controller_model_Control_Engineering_P.Dctleadlag2_P3_Size
                    section.data(16).logicalSrcIdx = 21;
                    section.data(16).dtTransOffset = 20;

                    ;% Basic_controller_model_Control_Engineering_P.Dctleadlag2_P3
                    section.data(17).logicalSrcIdx = 22;
                    section.data(17).dtTransOffset = 22;

                    ;% Basic_controller_model_Control_Engineering_P.Dctintegrator3_P1_Size
                    section.data(18).logicalSrcIdx = 23;
                    section.data(18).dtTransOffset = 23;

                    ;% Basic_controller_model_Control_Engineering_P.Dctintegrator3_P1
                    section.data(19).logicalSrcIdx = 24;
                    section.data(19).dtTransOffset = 25;

                    ;% Basic_controller_model_Control_Engineering_P.Dctintegrator3_P2_Size
                    section.data(20).logicalSrcIdx = 25;
                    section.data(20).dtTransOffset = 26;

                    ;% Basic_controller_model_Control_Engineering_P.Dctintegrator3_P2
                    section.data(21).logicalSrcIdx = 26;
                    section.data(21).dtTransOffset = 28;

                    ;% Basic_controller_model_Control_Engineering_P.Dctnotch4_P1_Size
                    section.data(22).logicalSrcIdx = 27;
                    section.data(22).dtTransOffset = 29;

                    ;% Basic_controller_model_Control_Engineering_P.Dctnotch4_P1
                    section.data(23).logicalSrcIdx = 28;
                    section.data(23).dtTransOffset = 31;

                    ;% Basic_controller_model_Control_Engineering_P.Dctnotch4_P2_Size
                    section.data(24).logicalSrcIdx = 29;
                    section.data(24).dtTransOffset = 32;

                    ;% Basic_controller_model_Control_Engineering_P.Dctnotch4_P2
                    section.data(25).logicalSrcIdx = 30;
                    section.data(25).dtTransOffset = 34;

                    ;% Basic_controller_model_Control_Engineering_P.Dctnotch4_P3_Size
                    section.data(26).logicalSrcIdx = 31;
                    section.data(26).dtTransOffset = 35;

                    ;% Basic_controller_model_Control_Engineering_P.Dctnotch4_P3
                    section.data(27).logicalSrcIdx = 32;
                    section.data(27).dtTransOffset = 37;

                    ;% Basic_controller_model_Control_Engineering_P.Dctnotch4_P4_Size
                    section.data(28).logicalSrcIdx = 33;
                    section.data(28).dtTransOffset = 38;

                    ;% Basic_controller_model_Control_Engineering_P.Dctnotch4_P4
                    section.data(29).logicalSrcIdx = 34;
                    section.data(29).dtTransOffset = 40;

                    ;% Basic_controller_model_Control_Engineering_P.Dctnotch4_P5_Size
                    section.data(30).logicalSrcIdx = 35;
                    section.data(30).dtTransOffset = 41;

                    ;% Basic_controller_model_Control_Engineering_P.Dctnotch4_P5
                    section.data(31).logicalSrcIdx = 36;
                    section.data(31).dtTransOffset = 43;

                    ;% Basic_controller_model_Control_Engineering_P.Saturation_UpperSat
                    section.data(32).logicalSrcIdx = 37;
                    section.data(32).dtTransOffset = 44;

                    ;% Basic_controller_model_Control_Engineering_P.Saturation_LowerSat
                    section.data(33).logicalSrcIdx = 38;
                    section.data(33).dtTransOffset = 45;

                    ;% Basic_controller_model_Control_Engineering_P.Saturation_UpperSat_d
                    section.data(34).logicalSrcIdx = 39;
                    section.data(34).dtTransOffset = 46;

                    ;% Basic_controller_model_Control_Engineering_P.Saturation_LowerSat_e
                    section.data(35).logicalSrcIdx = 40;
                    section.data(35).dtTransOffset = 47;

                    ;% Basic_controller_model_Control_Engineering_P.Constant1_Value
                    section.data(36).logicalSrcIdx = 41;
                    section.data(36).dtTransOffset = 48;

                    ;% Basic_controller_model_Control_Engineering_P.Constant_Value
                    section.data(37).logicalSrcIdx = 42;
                    section.data(37).dtTransOffset = 56;

                    ;% Basic_controller_model_Control_Engineering_P.Gain_Gain_g
                    section.data(38).logicalSrcIdx = 43;
                    section.data(38).dtTransOffset = 58;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_P.Selectencoder_CurrentSetting
                    section.data(1).logicalSrcIdx = 44;
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
        nTotSects     = 2;
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
        ;% Auto data (Basic_controller_model_Control_Engineering_B)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_B.SFunction
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% Basic_controller_model_Control_Engineering_B.ec_Ebox_o2
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 3;

                    ;% Basic_controller_model_Control_Engineering_B.ec_Ebox_o3
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_B.Startsetpoint
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Basic_controller_model_Control_Engineering_B.SFunction_b
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% Basic_controller_model_Control_Engineering_B.ec_Ebox_o1
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% Basic_controller_model_Control_Engineering_B.Output
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 4;

                    ;% Basic_controller_model_Control_Engineering_B.Buffer
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 5;

                    ;% Basic_controller_model_Control_Engineering_B.Gain1
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 8;

                    ;% Basic_controller_model_Control_Engineering_B.Dctleadlag2
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 9;

                    ;% Basic_controller_model_Control_Engineering_B.Dctintegrator3
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 10;

                    ;% Basic_controller_model_Control_Engineering_B.Dctnotch4
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 11;

                    ;% Basic_controller_model_Control_Engineering_B.Saturation
                    section.data(10).logicalSrcIdx = 12;
                    section.data(10).dtTransOffset = 12;

                    ;% Basic_controller_model_Control_Engineering_B.Constant1
                    section.data(11).logicalSrcIdx = 13;
                    section.data(11).dtTransOffset = 14;

                    ;% Basic_controller_model_Control_Engineering_B.Gain
                    section.data(12).logicalSrcIdx = 14;
                    section.data(12).dtTransOffset = 22;

                    ;% Basic_controller_model_Control_Engineering_B.Downsample
                    section.data(13).logicalSrcIdx = 15;
                    section.data(13).dtTransOffset = 24;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
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
        sectIdxOffset = 2;

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
        ;% Auto data (Basic_controller_model_Control_Engineering_DW)
        ;%
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_DW.Downsample_Buffer
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Basic_controller_model_Control_Engineering_DW.fileID
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% Basic_controller_model_Control_Engineering_DW.SFunction_RWORK
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% Basic_controller_model_Control_Engineering_DW.Dctleadlag2_RWORK
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 54;

                    ;% Basic_controller_model_Control_Engineering_DW.Dctintegrator3_RWORK
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 56;

                    ;% Basic_controller_model_Control_Engineering_DW.Dctnotch4_RWORK
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 58;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_DW.Velocity_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% Basic_controller_model_Control_Engineering_DW.Live_Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% Basic_controller_model_Control_Engineering_DW.eml_openfiles
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_DW.sfEvent
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_DW.NS
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_DW.NF
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_DW.is_active_c1_Basic_controller_m
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% Basic_controller_model_Control_Engineering_DW.busy
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Basic_controller_model_Control_Engineering_DW.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% Basic_controller_model_Control_Engineering_DW.fileID_not_empty
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 1;

                    ;% Basic_controller_model_Control_Engineering_DW.NF_not_empty
                    section.data(3).logicalSrcIdx = 16;
                    section.data(3).dtTransOffset = 2;

                    ;% Basic_controller_model_Control_Engineering_DW.busy_not_empty
                    section.data(4).logicalSrcIdx = 17;
                    section.data(4).dtTransOffset = 3;

                    ;% Basic_controller_model_Control_Engineering_DW.NS_not_empty
                    section.data(5).logicalSrcIdx = 18;
                    section.data(5).dtTransOffset = 4;

                    ;% Basic_controller_model_Control_Engineering_DW.eml_openfiles_not_empty
                    section.data(6).logicalSrcIdx = 19;
                    section.data(6).dtTransOffset = 5;

                    ;% Basic_controller_model_Control_Engineering_DW.eml_autoflush
                    section.data(7).logicalSrcIdx = 20;
                    section.data(7).dtTransOffset = 6;

                    ;% Basic_controller_model_Control_Engineering_DW.eml_autoflush_not_empty
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


    targMap.checksum0 = 642678769;
    targMap.checksum1 = 1884691429;
    targMap.checksum2 = 3006653366;
    targMap.checksum3 = 1298444517;

