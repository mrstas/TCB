// Special Functions - functions that can be mapped by the user to one of the numerous triggers

// The function definitions are not on this tab, but spread about. This is simply where they are assigned to the SF_Callback array.
// We also have "fake" functions for some that re-direct to the real function but without any parameters passed. 


// ----------------------------------------------------------------------------------------------------------------------------------------------->>
// LOAD SPECIAL FUNCTIONS INTO SF_CALLBACK ARRAY
// ----------------------------------------------------------------------------------------------------------------------------------------------->>
void LoadFunctionTriggers()
{

    // Here we setup the special functions list. The user can create up to MAX_FUNCTION_TRIGGERS (40 for now) pairs of Triggers-to-Functions.
    // Here we save the callback function address for each trigger. 
    for (int i = 0; i <MAX_FUNCTION_TRIGGERS; i++)
    {   // A valid function-trigger will have a function number and a TriggerID > 0
        if (eeprom.ramcopy.SF_Trigger[i].specialFunction != SF_NULL_FUNCTION && eeprom.ramcopy.SF_Trigger[i].TriggerID > 0)
        {
            //DebugSerial->print(F("TriggerID: "));
            //DebugSerial->print(eeprom.ramcopy.SF_Trigger[i].TriggerID);
            //DebugSerial->print(F(" Function #: "));
            //DebugSerial->println(eeprom.ramcopy.SF_Trigger[i].specialFunction);
            
            // Assign the callback function to the same index in the FunctionTrigger array
            // that the function definition occupies in our eeprom.ramcopy.SF_Trigger array
            switch (eeprom.ramcopy.SF_Trigger[i].specialFunction)
            {
                case SF_ENGINE_TOGGLE:
                    SF_Callback[i] = &SF_EngineToggle;
                    break;
                case SF_ENGINE_ON:
                    SF_Callback[i] = &SF_EngineOn;
                    break;
                case SF_ENGINE_OFF:
                    SF_Callback[i] = &SF_EngineOff;
                    break;
                case SF_TRANS_TOGGLE:
                    SF_Callback[i] = &SF_TransmissionToggle;
                    break;
                case SF_TRANS_ON:
                    SF_Callback[i] = &SF_TransmissionEngage;
                    break;
                case SF_TRANS_OFF:
                    SF_Callback[i] = &SF_TransmissionDisengage;
                    break;
                case SF_CANNON_FIRE:
                    SF_Callback[i] = &SF_FireCannon;
                    break;
                case SF_MECH_BARREL:
                    SF_Callback[i] = &SF_MechBarrel;
                    break;
                case SF_RECOIL_SERVO:
                    SF_Callback[i] = &SF_RecoilServo;
                    break;
                case SF_HI_FLASH:
                    SF_Callback[i] = &SF_HiFlash;
                    break;
                case SF_MG_FIRE:
                    SF_Callback[i] = &SF_MG_Start;
                    break;
                case SF_MG_OFF:
                    SF_Callback[i] = &SF_MG_Stop;
                    break;
                case SF_LIGHT1_TOGGLE:
                    SF_Callback[i] = &SF_Light1Toggle;
                    break;
                case SF_LIGHT1_ON:
                    SF_Callback[i] = &SF_Light1On;
                    break;
                case SF_LIGHT1_OFF:
                    SF_Callback[i] = &SF_Light1Off;
                    break;
                case SF_LIGHT2_TOGGLE:
                    SF_Callback[i] = &SF_Light2Toggle;
                    break;
                case SF_LIGHT2_ON:
                    SF_Callback[i] = &SF_Light2On;
                    break;
                case SF_LIGHT2_OFF:
                    SF_Callback[i] = &SF_Light2Off;
                    break;                
                case SF_RUNNINGLIGHTS_TOGGLE:
                    SF_Callback[i] = &SF_RunningLightsToggle;
                    break;
                case SF_RUNNINGLIGHTS_ON:
                    SF_Callback[i] = &SF_RunningLightsOn;
                    break;
                case SF_RUNNINGLIGHTS_OFF:
                    SF_Callback[i] = &SF_RunningLightsOff;
                    break;
                case SF_AUXOUT_TOGGLE:
                    SF_Callback[i] = &SF_AuxOutputToggle;
                    break;
                case SF_AUXOUT_ON:
                    SF_Callback[i] = &SF_AuxOutputOn;
                    break;
                case SF_AUXOUT_OFF:
                    SF_Callback[i] = &SF_AuxOutputOff;
                    break;
                case SF_AUXOUT_LEVEL:                       // Analog function
                    SF_Callback[i] = &AuxOutput_SetLevel;   // Doesn't need an SF_ mapped function, we can call it directly
                    break;
                case SF_AUXOUT_PRESETDIM:
                    SF_Callback[i] = &SF_AuxOutput_PresetDim;
                    break;
                case SF_AUXOUT_FLASH:
                    SF_Callback[i] = &SF_AuxOutputFlash;
                    break;
                case SF_AUXOUT_BLINK:
                    SF_Callback[i] = &SF_AuxOutputBlink;
                    break;
                case SF_AUXOUT_TOGGLEBLINK:
                    SF_Callback[i] = &SF_AuxOutputToggleBlink;
                    break;
                case SF_AUXOUT_REVOLVE:
                    SF_Callback[i] = &SF_AuxOutputRevolve;
                    break;
                case SF_AUXOUT_TOGGLEREVOLVE:
                    SF_Callback[i] = &SF_AuxOutputToggleRevolve;
                    break;                    
                case SF_USER_SOUND1_ONCE:
                    SF_Callback[i] = &SF_TriggerUserSound1;
                    break;
                case SF_USER_SOUND1_RPT:
                    SF_Callback[i] = &SF_UserSound1_Repeat;
                    break;
                case SF_USER_SOUND1_OFF:
                    SF_Callback[i] = &SF_UserSound1_Stop;
                    break;
                case SF_USER_SOUND2_ONCE:
                    SF_Callback[i] = &SF_TriggerUserSound2;
                    break;
                case SF_USER_SOUND2_RPT:
                    SF_Callback[i] = &SF_UserSound2_Repeat;
                    break;
                case SF_USER_SOUND2_OFF:
                    SF_Callback[i] = &SF_UserSound2_Stop;
                    break;
                case SF_OUTPUT_A_TOGGLE:
                    SF_Callback[i] = &SF_PortA_Toggle;
                    break;
                case SF_OUTPUT_A_ON:
                    SF_Callback[i] = &SF_PortA_On;
                    break; 
                case SF_OUTPUT_A_OFF:
                    SF_Callback[i] = &SF_PortA_Off;
                    break; 
                case SF_OUTPUT_B_TOGGLE:
                    SF_Callback[i] = &SF_PortA_Toggle;
                    break;
                case SF_OUTPUT_B_ON:
                    SF_Callback[i] = &SF_PortA_On;
                    break; 
                case SF_OUTPUT_B_OFF:
                    SF_Callback[i] = &SF_PortA_Off;
                    break; 
                case SF_ACCEL_LEVEL:
                    SF_Callback[i] = &SF_SetAccelRampFreq;
                    break;         
                case SF_DECEL_LEVEL:        
                    SF_Callback[i] = &SF_SetDecelRampFreq;
                    break;
                case SF_TURNMODE_1:        
                    SF_Callback[i] = &SF_TurnMode1;
                    break;                    
                case SF_TURNMODE_2:        
                    SF_Callback[i] = &SF_TurnMode2;
                    break;                    
                case SF_TURNMODE_3:        
                    SF_Callback[i] = &SF_TurnMode3;
                    break;                    
                case SF_SMOKER:                              // Analog function
                    SF_Callback[i] = &Smoker_ManualControl;   
                    break;
                case SF_MOTOR_A:                             // Analog function
                    SF_Callback[i] = &MotorA_ManualControl;   
                    break;
                case SF_MOTOR_B:                             // Analog function
                    SF_Callback[i] = &MotorB_ManualControl;   
                    break;
                case SF_SERVO1_PASS:                         // Analog function
                    SF_Callback[i] = &Servo1_Passthrough;   
                    break;                    
                case SF_SERVO2_PASS:                         // Analog function
                    SF_Callback[i] = &Servo2_Passthrough;   
                    break;                    
                case SF_SERVO3_PASS:                         // Analog function
                    SF_Callback[i] = &Servo3_Passthrough;   
                    break;                    
                case SF_SERVO4_PASS:                         // Analog function
                    SF_Callback[i] = &Servo4_Passthrough;   
                    break;                    
                case SF_BARREL_ON:
                    SF_Callback[i] = &SF_BarrelStab_On;   
                    break;                    
                case SF_BARREL_OFF:
                    SF_Callback[i] = &SF_BarrelStab_Off;   
                    break;                    
                case SF_BARREL_TOGGLE:
                    SF_Callback[i] = &SF_BarrelStab_Toggle;   
                    break;                                        
                case SF_BARREL_LEVEL:                        // Analog function
                    SF_Callback[i] = &SetBarrelSensitivity;   
                    break;                    
                case SF_HILLS_ON:
                    SF_Callback[i] = &SF_HillPhysics_On;   
                    break;                    
                case SF_HILLS_OFF:
                    SF_Callback[i] = &SF_HillPhysics_Off;   
                    break;                    
                case SF_HILLS_TOGGLE:
                    SF_Callback[i] = &SF_HillPhysics_Toggle;   
                    break;                                        
                case SF_HILLS_LEVEL:                         // Analog function
                    SF_Callback[i] = &SetHillSensitivity;   
                    break;                    
                case SF_USER_FUNC_1:
                    SF_Callback[i] = &SF_UserFunc1;
                    break;
                case SF_USER_FUNC_2:
                    SF_Callback[i] = &SF_UserFunc2;
                    break;                    
                case SF_USER_ANLG_1:
                    SF_Callback[i] = &User_Analog_Function1;
                    break;
                case SF_USER_ANLG_2:
                    SF_Callback[i] = &User_Analog_Function2;
                    break;
            }
        }
    }
}

uint8_t CountTriggers(void)
{
    uint8_t tCount = 0;
    
    // A valid function-trigger will have a function number and a TriggerID > 0
    for (int i = 0; i <MAX_FUNCTION_TRIGGERS; i++)
    {   
        if (eeprom.ramcopy.SF_Trigger[i].specialFunction != SF_NULL_FUNCTION && eeprom.ramcopy.SF_Trigger[i].TriggerID > 0) tCount += 1;
    }
    return tCount; 
}


// ----------------------------------------------------------------------------------------------------------------------------------------------->>
// CONVENIENCE FUNCTION - GET TRIGGER NAME FROM TRIGGER ID
// ----------------------------------------------------------------------------------------------------------------------------------------------->>
void PrintTriggerDescription(_special_function sf, uint16_t TriggerID)
{
    uint8_t TriggerAction = 0;

    // Is the selected function digital or analog:
    boolean sf_digital = isSpecialFunctionDigital(sf);
    
    // Turret stick triggers
    if (TriggerID > 0 && TriggerID <= MAX_SPEC_POS)
    {   
        // Trigger action in this case is equal to the Trigger ID
        DebugSerial->print(F("Turret Stick - "));
        DebugSerial->print(TurretStickPosition(TriggerID));
    }
    // External I/O source. The Trigger Source is the integer value of the division by the ports multiplier (discard remainder)
    else if (TriggerID >= trigger_id_multiplier_ports && TriggerID < trigger_id_multiplier_auxchannel)
    {
        int portNum = TriggerID / trigger_id_multiplier_ports;
        DebugSerial->print(F("External Input "));
        switch (portNum)
        {   case 1: DebugSerial->print(F("A")); break;
            case 2: DebugSerial->print(F("B")); break;
        }
        PrintSpaceDash();
        // Up to this point we now have something like "External Input A - "
        if (sf_digital)
        {
            // The remainder is the action (on/off if digital, or variable if analog)
            TriggerAction = getTriggerActionFromTriggerID(TriggerID);
            if (TriggerAction == 0) DebugSerial->print(F("Off")); 
            if (TriggerAction == 1) DebugSerial->print(F("On"));
        }
        else                         
        {
            DebugSerial->print(F("Variable"));
        }
    }
    // Aux RC Channel Trigger
    else if (TriggerID >= trigger_id_multiplier_auxchannel)
    {
        int channelNum = TriggerID / trigger_id_multiplier_auxchannel;
        DebugSerial->print(F("Aux Channel "));
        DebugSerial->print(channelNum, DEC);
        PrintSpaceDash();
        // Up to this point we now have something like "Aux Channel 4 - "
        if (sf_digital)
        {
            // But we still need to append the position. Complicating matters is that the text description of the switch position
            // depends on how many positions have been defined for that switch
            // If for example the position is 5, and this is a 2-position switch, we want to actually display a description that says
            // "Pos 2 (of 2)".
            TriggerAction = getTriggerActionFromTriggerID(TriggerID);
            int numPositions = getNumPositionsFromTriggerID(TriggerID);
            DebugSerial->print(F("Pos "));
            switch (numPositions)
            {
                case 2:
                    // The only two valid positions in this case are really just 1 & 5, but
                    // we split the difference at 3 for robustness
                    if (TriggerAction <= 3) DebugSerial->print(F("1 (of 2)"));
                    if (TriggerAction >  3) DebugSerial->print(F("2 (of 2)"));
                    break;
                case 3:
                    // Again here the only valid positions are 1,3 and 5 but this works as well
                    if (TriggerAction <  3) DebugSerial->print(F("1 (of 3)"));
                    if (TriggerAction == 3) DebugSerial->print(F("2 (of 3)"));
                    if (TriggerAction >  3) DebugSerial->print(F("3 (of 3)"));
                    break;
                case 5:
                    DebugSerial->print(TriggerAction, DEC);
                    DebugSerial->print(F(" (of 5)"));
                    break;
            }
        }
        else
        {
            DebugSerial->print(F("Variable"));
        }
    }
}

uint8_t getNumPositionsFromTriggerID(uint16_t TriggerID)
{
    // Turret stick trigger - num positions is not relevant
    if (TriggerID >0 && TriggerID <= MAX_SPEC_POS)
        return 0;

    // External input trigger - if digital, these are only 2-position switches:
    // On (line connected to ground) or Off (line disconnected/held high by internal pullups)
    if (TriggerID >= trigger_id_multiplier_ports && TriggerID < trigger_id_multiplier_auxchannel)
        return 2;

    // Aux Channel switches - if digital, these can be 2, 3 or 5 position switches (for now)
    if (TriggerID >= trigger_id_multiplier_auxchannel)
    {
        // We will walk through an example as we calculate these values.
        // Assume the Trigger ID is 4035
        // channelNum will equal 4 (Aux Channel 4)
        int channelNum = TriggerID / trigger_id_multiplier_auxchannel;
        // NumPos_CurPos will equal 35. 3 is the number of positions the switch has, 5 is the trigger position number
        // Recall that for a 3-position switch, the 3 possible positions are actually 1, 3, and 5
        int NumPos_CurPos = TriggerID - (channelNum * trigger_id_multiplier_auxchannel);
        // NumPositions will equal 3. This is the number of positions the switch is capable of
        int NumPositions = NumPos_CurPos / switch_pos_multiplier;
        return NumPositions;
        // Trigger Action will equal 5, we don't need it in this function though
        // int TriggerAction = NumPos_CurPos - (NumPositions * switch_pos_multiplier);
    }

    // Any other case, return 0
        return 0;
}

uint8_t getTriggerActionFromTriggerID(uint16_t TriggerID)
{   // Remember also, for analog triggers, there is no "action"

    int TriggerAction = 0;

    // Turret stick trigger - action *is* the trigger ID
    if (TriggerID >0 && TriggerID <= MAX_SPEC_POS)
        return TriggerID;   // should auto-cast to uint8_t. Anyway it doesn't matter, we won't be looking up TriggerActions for turret stick

    // External input trigger - if digital, these are only 2-position switches:
    // On (line connected to ground) or Off (line disconnected/held high by internal pullups)
    if (TriggerID >= trigger_id_multiplier_ports && TriggerID < trigger_id_multiplier_auxchannel)
    {
        int portNum = TriggerID / trigger_id_multiplier_ports;

        // The remainder is the action (1/0)
        TriggerAction = TriggerID - (portNum * trigger_id_multiplier_ports);
        return TriggerAction;
    }

    // Aux Channel switches - this is the tricky case that we have this function for in the first place
    if (TriggerID >= trigger_id_multiplier_auxchannel)
    {
        // We will walk through an example as we calculate these values.
        // Assume the Trigger ID is 4035
        // channelNum will equal 4 (Aux Channel 4)
        int channelNum = TriggerID / trigger_id_multiplier_auxchannel;
        // NumPos_CurPos will equal 35. "3" is the number of positions the switch has, "5" is the trigger action we want.
        // It is equal to "position 3" because for a three-position switch, the three positions are actually defined as action 1,3,5
        int NumPos_CurPos = TriggerID - (channelNum * trigger_id_multiplier_auxchannel);
        // NumPositions will equal 3. This is the number of positions the switch is capable of
        int NumPositions = NumPos_CurPos / switch_pos_multiplier;
        // Trigger Action will equal 5
        TriggerAction = NumPos_CurPos - (NumPositions * switch_pos_multiplier);
        return TriggerAction;
    }

    // Any other case, return 0
    return 0;
}

uint8_t getAuxChannelNumberFromTriggerID(uint16_t TriggerID)
{
    if (TriggerID >= trigger_id_multiplier_auxchannel)
    {
        return TriggerID / trigger_id_multiplier_auxchannel;
    }
    else
    {
        return 0;
    }
}


// ----------------------------------------------------------------------------------------------------------------------------------------------->>
// RE-DIRECT FUNCTIONS - FOR FUNCTIONS THAT DON'T NEED PARAMETERS
// ----------------------------------------------------------------------------------------------------------------------------------------------->>
// These functions don't need a variable passed, but we need a function with a uint16_t 
// for our function pointer. So to make using these functions elsewhere in the code
// easier, we create SF_functions that take an (ignored) parameter and then just call
// the function we actually want. 
void SF_EngineToggle(uint16_t ignoreMe)         { EngineToggle();           }
void SF_EngineOn(uint16_t ignoreMe)             { EngineOn();               }
void SF_EngineOff(uint16_t ignoreMe)            { EngineOff();              }
void SF_TransmissionToggle(uint16_t ignoreMe)   { TransmissionToggle();     }
void SF_TransmissionEngage(uint16_t ignoreMe)   { TransmissionEngage();     }
void SF_TransmissionDisengage(uint16_t ignoreMe){ TransmissionDisengage();  }
void SF_FireCannon(uint16_t ignoreMe)           { FireCannon();             }
void SF_MechBarrel(uint16_t ignoreMe)           { MechBarrel();             }
void SF_RecoilServo(uint16_t ignoreMe)          { TriggerServoRecoil();     }
void SF_HiFlash(uint16_t ignoreMe)              { MuzzleFlash();            }
void SF_MG_Start(uint16_t ignoreMe)             { MG_Start();               }
void SF_MG_Stop(uint16_t ignoreMe)              { MG_Stop();                }
void SF_Light1Toggle(uint16_t ignoreMe)         { Light1Toggle();           }
void SF_Light1On(uint16_t ignoreMe)             { Light1On();               }
void SF_Light1Off(uint16_t ignoreMe)            { Light1Off();              }
void SF_Light2Toggle(uint16_t ignoreMe)         { Light2Toggle();           }
void SF_Light2On(uint16_t ignoreMe)             { Light2On();               }
void SF_Light2Off(uint16_t ignoreMe)            { Light2Off();              }
void SF_RunningLightsToggle(uint16_t ignoreMe)  { RunningLightsToggle();    }
void SF_RunningLightsOn(uint16_t ignoreMe)      { RunningLightsOn();        }
void SF_RunningLightsOff(uint16_t ignoreMe)     { RunningLightsOff();       }
void SF_AuxOutputToggle(uint16_t ignoreMe)      { AuxOutputToggle();        }
void SF_AuxOutputOn(uint16_t ignoreMe)          { AuxOutputOn();            }
void SF_AuxOutputOff(uint16_t ignoreMe)         { AuxOutputOff();           }
void SF_AuxOutput_PresetDim(uint16_t ignoreMe)  { AuxOutput_PresetDim();    }
void SF_AuxOutputFlash(uint16_t ignoreMe)       { AuxOutputFlash();         }
void SF_AuxOutputBlink(uint16_t ignoreMe)       { AuxOutputBlink();         }
void SF_AuxOutputToggleBlink(uint16_t ignoreMe) { AuxOutputToggleBlink();   }
void SF_AuxOutputRevolve(uint16_t ignoreMe)     { AuxOutputRevolve();       }
void SF_AuxOutputToggleRevolve(uint16_t ignoreMe){ AuxOutputToggleRevolve();}
void SF_TriggerUserSound1(uint16_t ignoreMe)    { TriggerUserSound1();      }
void SF_UserSound1_Repeat(uint16_t ignoreMe)    { UserSound1_Repeat();      }
void SF_UserSound1_Stop(uint16_t ignoreMe)      { UserSound1_Stop();        }
void SF_TriggerUserSound2(uint16_t ignoreMe)    { TriggerUserSound2();      }
void SF_UserSound2_Repeat(uint16_t ignoreMe)    { UserSound2_Repeat();      }
void SF_UserSound2_Stop(uint16_t ignoreMe)      { UserSound2_Stop();        }
void SF_PortA_Toggle(uint16_t ignoreMe)         { PortA_Toggle();           }
void SF_PortA_On(uint16_t ignoreMe)             { PortA_On();               }
void SF_PortA_Off(uint16_t ignoreMe)            { PortA_Off();              }
void SF_PortB_Toggle(uint16_t ignoreMe)         { PortB_Toggle();           }
void SF_PortB_On(uint16_t ignoreMe)             { PortB_On();               }
void SF_PortB_Off(uint16_t ignoreMe)            { PortB_Off();              }
void SF_BarrelStab_On(uint16_t ignoreMe)        { EnableBarrelStabilization(true);  }
void SF_BarrelStab_Off(uint16_t ignoreMe)       { EnableBarrelStabilization(false); }
void SF_BarrelStab_Toggle(uint16_t ignoreMe)    { ToggleBarrelStabilization();      }
void SF_HillPhysics_On(uint16_t ignoreMe)       { EnableHillPhysics(true);  }
void SF_HillPhysics_Off(uint16_t ignoreMe)      { EnableHillPhysics(false); }
void SF_HillPhysics_Toggle(uint16_t ignoreMe)   { ToggleHillPhysics();      }
void SF_UserFunc1(uint16_t ignoreMe)            { UserFunction1();          }
void SF_UserFunc2(uint16_t ignoreMe)            { UserFunction2();          }


// ----------------------------------------------------------------------------------------------------------------------------------------------->>
// INPUT PARAMETER SCALING
// ----------------------------------------------------------------------------------------------------------------------------------------------->>
// So-called "analog" special functions must all accept a uint16_t (two byte unsigned integer) that can range from 0-1023 (10-bit number),
// however the "analog" inputs may be a different range from that. 
// Analog inputs (on I/O port A or B) use analogRead which actually does return a value from 0-1023 on the Atmega2560, so we don't need to scale those. 
// But an RC channel will have a range from 1000 - 2000 approximately (more specifically, it will have a value from pulseMin to pulseMax)
// This function converts this RC channel scale to the expected scale for analog special functions
uint16_t ScaleAuxChannelPulse_to_AnalogInput(int chan)
{
    // Just to be sure we don't end up with anything out of bounds: 
    long val = constrain(Radio.AuxChannel[chan].pulse, Radio.AuxChannel[chan].Settings->pulseMin, Radio.AuxChannel[chan].Settings->pulseMax);
    // Map pulse within the pulse range to a new value within our analog special function range: 
    val = map(val, Radio.AuxChannel[chan].Settings->pulseMin, Radio.AuxChannel[chan].Settings->pulseMax, ANALOG_SPECFUNCTION_MIN_VAL, ANALOG_SPECFUNCTION_MAX_VAL);
    return val;
}


// ----------------------------------------------------------------------------------------------------------------------------------------------->>
// RE-DIRECT FUNCTIONS - FOR ANALOG FUNCTIONS WITH PARAMETER
// ----------------------------------------------------------------------------------------------------------------------------------------------->>
// This function maps the 0-1023 analog input to a range from 1-MAX_SKIP_NUM expected by the two 
// drive functions used to change the acceleration/deceleration constraints
uint8_t SkipNum_from_AnalogInput(uint16_t val)
{
    long skipNum = constrain(val, ANALOG_SPECFUNCTION_MIN_VAL, ANALOG_SPECFUNCTION_MAX_VAL);
    skipNum = map(skipNum, ANALOG_SPECFUNCTION_MIN_VAL, ANALOG_SPECFUNCTION_MAX_VAL, 1, MAX_SKIP_NUM);
    return skipNum; 
}
// These re-direct functions take care of mapping the analog value to the value expected by the accel/decel functions
void SF_SetAccelRampFreq(uint16_t val)
{ 
    uint8_t sn = SkipNum_from_AnalogInput(val); 
    // Only update if changed
    if (sn != Driver.getAccelRampFrequency())
    {
        Driver.setAccelRampFrequency(sn); 
        if (DEBUG) { DebugSerial->print(F("Set Accel Ramp Level: ")); DebugSerial->println(sn); } 
    }
}
void SF_SetDecelRampFreq(uint16_t val)
{ 
    uint8_t sn = SkipNum_from_AnalogInput(val); 
    // Only update if changed
    if (sn != Driver.getDecelRampFrequency())
    {
        Driver.setDecelRampFrequency(sn); 
        if (DEBUG) { DebugSerial->print(F("Set Decel Ramp Level: ")); DebugSerial->println(sn); }
    }
}

// These re-direct functions pass the correct mode number
void SF_TurnMode1(uint16_t ignoreMe)            { if (Driver.getTurnMode() != 1) { Driver.setTurnMode(1); if (DEBUG) DebugSerial->println(F("Set Turn Mode: 1")); } }
void SF_TurnMode2(uint16_t ignoreMe)            { if (Driver.getTurnMode() != 2) { Driver.setTurnMode(2); if (DEBUG) DebugSerial->println(F("Set Turn Mode: 2")); } }
void SF_TurnMode3(uint16_t ignoreMe)            { if (Driver.getTurnMode() != 3) { Driver.setTurnMode(3); if (DEBUG) DebugSerial->println(F("Set Turn Mode: 3")); } }

// Barrel Stabilization and Hill Physics sensitivy numbers can vary between 1-100. 
void SetBarrelSensitivity(uint16_t level)       
{ 
    uint8_t bs = map(level, ANALOG_SPECFUNCTION_MIN_VAL, ANALOG_SPECFUNCTION_MAX_VAL, 1, 100); 
    // Only update if changed
    if (BarrelSensitivity != bs)
    {
        BarrelSensitivity = bs; 
        if (DEBUG) { DebugSerial->print(F("Set Barrel Sensitivity: ")); PrintLnPct(bs); } 
    }
}  

void SetHillSensitivity(uint16_t level)         
{ 
    uint8_t hs = map(level, ANALOG_SPECFUNCTION_MIN_VAL, ANALOG_SPECFUNCTION_MAX_VAL, 1, 100); 
    // Only update if changed
    if (HillSensitivity != hs)
    {
        HillSensitivity = hs;     
        if (DEBUG) { DebugSerial->print(F("Set Hill Sensitivity: ")); PrintLnPct(hs); } 
    }
}  

// Servo pass-through functions
void Servo1_Passthrough(uint16_t level)
{   // Recall, all analog special functions must receive values from 0-1023. But instead of using the map function here, we just set the external range
    // of the servo object to that range and the motor class will take care of it. 
    //if (Servo1_Available) Servo1->setSpeed(map(level, ANALOG_SPECFUNCTION_MIN_VAL, ANALOG_SPECFUNCTION_MAX_VAL, MOTOR_MAX_REVSPEED, MOTOR_MAX_FWDSPEED));
    if (Servo1_Available) Servo1->setSpeed(level);
}
void Servo2_Passthrough(uint16_t level)
{
    if (Servo2_Available) Servo2->setSpeed(level);
}
void Servo3_Passthrough(uint16_t level)
{
    if (Servo3_Available) Servo3->setSpeed(level);
}
void Servo4_Passthrough(uint16_t level)
{
    if (Servo4_Available) Servo4->setSpeed(level);
}

// Onboard motor pass-through functions - if not used for drive or turret control
void MotorA_ManualControl(uint16_t level)
{
    //if (MotorA_Available) MotorA->setSpeed();
}
void MotorB_ManualControl(uint16_t level)
{
    // We already set the MotorB external range to ANALOG_SPECFUNCTION_MIN_VAL to ANALOG_SPECFUNCTION_MAX_VAL for the MotorB object in
    // InstantiateMotorObjects()
    if (MotorB_Available) MotorB->setSpeed(level);
}



// ----------------------------------------------------------------------------------------------------------------------------------------------->>
// SAVE ADJUSTMENTS
// ----------------------------------------------------------------------------------------------------------------------------------------------->>
// The user is able to modify several variables on the fly that also have default values in EEPROM. Although we don't want to update EEPROM
// every time an adjustment is made, because that would wear out the EEPROM, we do want to save them in certain cases. 
// A) The user presses the input button - this causes a save before we dump the sytem info. 
// That's the only case for now... but we might think of others. 
void SaveAdjustments()
{
    // Turn Mode - single byte
    eeprom.ramcopy.TurnMode = Driver.getTurnMode();
    EEPROM.updateByte(offsetof(_eeprom_data, TurnMode), eeprom.ramcopy.TurnMode);

    // Accel/Decel Level
    eeprom.ramcopy.AccelSkipNum = Driver.getAccelRampFrequency();
    EEPROM.updateByte(offsetof(_eeprom_data, AccelSkipNum), eeprom.ramcopy.AccelSkipNum);
    eeprom.ramcopy.DecelSkipNum = Driver.getDecelRampFrequency();
    EEPROM.updateByte(offsetof(_eeprom_data, DecelSkipNum), eeprom.ramcopy.DecelSkipNum);
    
    // Barrel stabilization/Hill physics sensitivity
    eeprom.ramcopy.BarrelSensitivity = BarrelSensitivity;
    EEPROM.updateByte(offsetof(_eeprom_data, BarrelSensitivity), eeprom.ramcopy.BarrelSensitivity);
    eeprom.ramcopy.HillSensitivity = HillSensitivity;
    EEPROM.updateByte(offsetof(_eeprom_data, HillSensitivity), eeprom.ramcopy.HillSensitivity);

    // Aux Output level
    EEPROM.updateByte(offsetof(_eeprom_data, AuxLightPresetDim), eeprom.ramcopy.AuxLightPresetDim);

    // ANY OTHER SPECIAL FUNCTIONS THAT ADJUST PROGRAM SETTINGS STORED IN EEPROM, BE SURE TO ADD HERE
    // ...
}






