#include "cardsdatabase.h"

CardsDataBase::RecordEntry CardsDataBase::getEntry(SCDefs::DeviceTypes type, uint16_t id)
{
    return mData.value(type).value(id);
}

QMapIterator<uint16_t, CardsDataBase::RecordEntry> CardsDataBase::getEntryIterator(SCDefs::DeviceTypes type)
{
    return QMapIterator<uint16_t, RecordEntry>(mData.value(type));
}

QMap<SCDefs::DeviceTypes, QMap<uint16_t, CardsDataBase::RecordEntry>> CardsDataBase::mData = {
    {
        SCDefs::DeviceTypes::ASPIRR, {
            { AspiratorID::Power,             { "power",             "", Record(AspiratorID::Power,             SCDefs::defBoolData  ), true  } },
            { AspiratorID::PressureSet,       { "pressureSet",       "", Record(AspiratorID::PressureSet,       SCDefs::defIntData   ), true  } },
            { AspiratorID::PressureMeas,      { "pressureMeas",      "", Record(AspiratorID::PressureMeas,      SCDefs::defIntData   ), false } },
            { AspiratorID::UnderpressureSet,  { "underpressureSet",  "", Record(AspiratorID::UnderpressureSet,  SCDefs::defIntData   ), true  } },
            { AspiratorID::UnderpressureMeas, { "underpressureMeas", "", Record(AspiratorID::UnderpressureMeas, SCDefs::defIntData   ), false } },
            { AspiratorID::VacReset,          { "vacuumReset",       "", Record(AspiratorID::VacReset,          SCDefs::defBoolData  ), false } },
            { AspiratorID::Auto,              { "autoMode",          "", Record(AspiratorID::Auto,              SCDefs::defBoolData  ), false } },
            { AspiratorID::VolumeLevel,       { "volumeLevel",       "", Record(AspiratorID::VolumeLevel,       SCDefs::defUCharData ), true  } },
            { AspiratorID::Voice,             { "voice",             "", Record(AspiratorID::Voice,             SCDefs::defUCharData ), true  } },
            { AspiratorID::FailureCode,       { "failureCode",       "", Record(AspiratorID::FailureCode,       SCDefs::defUCharData ), false } },
            { AspiratorID::ProfileID,         { "profileId",         "", Record(AspiratorID::ProfileID,         SCDefs::defUIntData  ), false } }
        }
    },
    {
        SCDefs::DeviceTypes::INSUF, {
            { InsufID::Power,                { "power",                "", Record(InsufID::Power,                SCDefs::defBoolData  ), true  } },
            { InsufID::PressureInput,        { "pressureInput",        "", Record(InsufID::PressureInput,        SCDefs::defIntData   ), false } },
            { InsufID::PressureSet,          { "pressureSet",          "", Record(InsufID::PressureSet,          SCDefs::defIntData   ), true  } },
            { InsufID::PressureMeas,         { "pressureMeas",         "", Record(InsufID::PressureMeas,         SCDefs::defIntData   ), false } },
            { InsufID::ExpenseSet,           { "expenseSet",           "", Record(InsufID::ExpenseSet,           SCDefs::defIntData   ), true  } },
            { InsufID::ExpenseMeas,          { "expenseMeas",          "", Record(InsufID::ExpenseMeas,          SCDefs::defIntData   ), false } },
            { InsufID::VolumeMeas,           { "volumeMeas",           "", Record(InsufID::VolumeMeas,           SCDefs::defFloatData ), false } },
            { InsufID::VolumeReset,          { "volumeReset",          "", Record(InsufID::VolumeReset,          SCDefs::defBoolData  ), false } },
            { InsufID::SpeedUp,              { "speedUp",              "", Record(InsufID::SpeedUp,              SCDefs::defBoolData  ), false } },
            { InsufID::GasOn,                { "gasOn",                "", Record(InsufID::GasOn,                SCDefs::defBoolData  ), false } },
            { InsufID::VolumeLevel,          { "volumeLevel",          "", Record(InsufID::VolumeLevel,          SCDefs::defUCharData ), true  } },
            { InsufID::Voice,                { "voice",                "", Record(InsufID::Voice,                SCDefs::defUCharData ), true  } },
            { InsufID::FailureCode,          { "failureCode",          "", Record(InsufID::FailureCode,          SCDefs::defUCharData ), false } },
            { InsufID::UnderpressureWrn,     { "underpressureWrn",     "", Record(InsufID::UnderpressureWrn,     SCDefs::defBoolData  ), false } },
            { InsufID::InsufflationPressure, { "insufflationPressure", "", Record(InsufID::InsufflationPressure, SCDefs::defFloatData ), false } },
            { InsufID::InsufflationExpense,  { "insufflationExpense",  "", Record(InsufID::InsufflationExpense,  SCDefs::defFloatData ), false } },
            { InsufID::GasType,              { "gasType",              "", Record(InsufID::GasType,              SCDefs::defBoolData  ), false } },
            { InsufID::WDSensorType,         { "wdSensorType",         "", Record(InsufID::WDSensorType,         SCDefs::defBoolData  ), false } },
            { InsufID::WDSensorType,         { "wdZero",               "", Record(InsufID::WDSensorType,         SCDefs::defIntData   ), false } },
            { InsufID::PressureSensorZero,   { "pressureSensorZero",   "", Record(InsufID::PressureSensorZero,   SCDefs::defIntData   ), false } },
            { InsufID::ExpenseSensorZero,    { "expenseSensorZero",    "", Record(InsufID::ExpenseSensorZero,    SCDefs::defIntData   ), false } },
            { InsufID::KlapanZero,           { "klapanZero",           "", Record(InsufID::KlapanZero,           SCDefs::defIntData   ), false } },
            { InsufID::KlapanOffset,         { "klapanOffset",         "", Record(InsufID::KlapanOffset,         SCDefs::defIntData   ), false } },
            { InsufID::KlapanTilt,           { "klapanTilt",           "", Record(InsufID::KlapanTilt,           SCDefs::defFloatData ), false } },
            { InsufID::ConfigBlock,          { "configBlock",          "", Record(InsufID::ConfigBlock,          SCDefs::defBoolData  ), false } },
            { InsufID::ProfileID,            { "profileId",            "", Record(InsufID::ProfileID,            SCDefs::defUIntData  ), false } }
        }
    },
    {
        SCDefs::DeviceTypes::ESU, {
            { ESUID::Power,                { "power",                "", Record(ESUID::Power,                SCDefs::defBoolData       ), true  } },
            { ESUID::FailureCode,          { "failureCode",          "", Record(ESUID::FailureCode,          SCDefs::defUCharData      ), false } },
            { ESUID::VolumeLevel,          { "volumeLevel",          "", Record(ESUID::VolumeLevel,          SCDefs::defUCharData      ), true  } },
            { ESUID::Language,             { "language",             "", Record(ESUID::Language,             SCDefs::defUCharArrayData ), true  } },
            { ESUID::MaxActivationTime,    { "maxActivationTime",    "", Record(ESUID::MaxActivationTime,    SCDefs::defUCharData      ), true  } },
            { ESUID::IrrigationControl,    { "irrigationControl",    "", Record(ESUID::IrrigationControl,    SCDefs::defBoolData       ), true  } },
            { ESUID::IrrigationStartDelay, { "irrigationStartDelay", "", Record(ESUID::IrrigationStartDelay, SCDefs::defUIntData       ), true  } },
            { ESUID::SocketActive,         { "socketActive",         "", Record(ESUID::SocketActive,         SCDefs::defUCharData      ), true  } },
            { ESUID::SocketExpanded,       { "socketExpanded",       "", Record(ESUID::SocketExpanded,       SCDefs::defUCharData      ), true  } },
            { ESUID::S1CutPower,           { "S1cutPower",           "", Record(ESUID::S1CutPower,           SCDefs::defUShortData     ), true  } },
            { ESUID::S1CutEffect,          { "S1cutEffect",          "", Record(ESUID::S1CutEffect,          SCDefs::defUShortData     ), true  } },
            { ESUID::S1CutMode,            { "S1cutMode",            "", Record(ESUID::S1CutMode,            SCDefs::defUCharData      ), true  } },
            { ESUID::S1CoagPower,          { "S1coagPower",          "", Record(ESUID::S1CoagPower,          SCDefs::defUShortData     ), true  } },
            { ESUID::S1CoagEffect,         { "S1coagEffect",         "", Record(ESUID::S1CoagEffect,         SCDefs::defUShortData     ), true  } },
            { ESUID::S1CoagMode,           { "S1coagMode",           "", Record(ESUID::S1CoagMode,           SCDefs::defUCharData      ), true  } },
            { ESUID::S2CutPower,           { "S2cutPower",           "", Record(ESUID::S2CutPower,           SCDefs::defUShortData     ), true  } },
            { ESUID::S2CutEffect,          { "S2cutEffect",          "", Record(ESUID::S2CutEffect,          SCDefs::defUShortData     ), true  } },
            { ESUID::S2CutMode,            { "S2cutMode",            "", Record(ESUID::S2CutMode,            SCDefs::defUCharData      ), true  } },
            { ESUID::S2CoagPower,          { "S2coagPower",          "", Record(ESUID::S2CoagPower,          SCDefs::defUShortData     ), true  } },
            { ESUID::S2CoagEffect,         { "S2coagEffect",         "", Record(ESUID::S2CoagEffect,         SCDefs::defUShortData     ), true  } },
            { ESUID::S2CoagMode,           { "S2coagMode",           "", Record(ESUID::S2CoagMode,           SCDefs::defUCharData      ), true  } },
            { ESUID::S3CutPower,           { "S3cutPower",           "", Record(ESUID::S3CutPower,           SCDefs::defUShortData     ), true  } },
            { ESUID::S3CutEffect,          { "S3cutEffect",          "", Record(ESUID::S3CutEffect,          SCDefs::defUShortData     ), true  } },
            { ESUID::S3CutMode,            { "S3cutMode",            "", Record(ESUID::S3CutMode,            SCDefs::defUCharData      ), true  } },
            { ESUID::S3CoagPower,          { "S3coagPower",          "", Record(ESUID::S3CoagPower,          SCDefs::defUShortData     ), true  } },
            { ESUID::S3CoagEffect,         { "S3coagEffect",         "", Record(ESUID::S3CoagEffect,         SCDefs::defUShortData     ), true  } },
            { ESUID::S3CoagMode,           { "S3coagMode",           "", Record(ESUID::S3CoagMode,           SCDefs::defUCharData      ), true  } },
            { ESUID::AutostartDelay,       { "S3AutostartDelay",     "", Record(ESUID::AutostartDelay,       SCDefs::defUIntData       ), true  } },
            { ESUID::AutostopResistance,   { "S3AutostopResistance", "", Record(ESUID::AutostopResistance,   SCDefs::defUShortData     ), true  } }
        }
    },
    {
        SCDefs::DeviceTypes::HysteroPump, {
            { HystID::Power,          { "power",          "", Record(HystID::Power,          SCDefs::defBoolData  ), true  } },
            { HystID::PressureSet,    { "pressureSet",    "", Record(HystID::PressureSet,    SCDefs::defIntData   ), true  } },
            { HystID::PressureMeas,   { "pressureMeas",   "", Record(HystID::PressureMeas,   SCDefs::defIntData   ), false } },
            { HystID::FlowSet,        { "flowSet",        "", Record(HystID::FlowSet,        SCDefs::defFloatData ), true  } },
            { HystID::FlowMeas,       { "flowMeas",       "", Record(HystID::FlowMeas,       SCDefs::defFloatData ), false } },
            { HystID::ExpenseCrit,    { "expenseCrit",    "", Record(HystID::ExpenseCrit,    SCDefs::defFloatData ), true  } },
            { HystID::ExpenseMeas,    { "expenseMeas",    "", Record(HystID::ExpenseMeas,    SCDefs::defFloatData ), false } },
            { HystID::DeficitCrit,    { "deficitCrit",    "", Record(HystID::DeficitCrit,    SCDefs::defFloatData ), true  } },
            { HystID::DeficitMeas,    { "deficitMeas",    "", Record(HystID::DeficitMeas,    SCDefs::defFloatData ), false } },
            { HystID::TubusCell,      { "tubusCell",      "", Record(HystID::TubusCell,      SCDefs::defUCharData ), true  } },
            { HystID::TubusTypeCell1, { "cell1Tubus",     "", Record(HystID::TubusTypeCell1, SCDefs::defUCharData ), true  } },
            { HystID::TubusTypeCell2, { "cell2Tubus",     "", Record(HystID::TubusTypeCell2, SCDefs::defUCharData ), true  } },
            { HystID::TubusTypeCell3, { "cell3Tubus",     "", Record(HystID::TubusTypeCell3, SCDefs::defUCharData ), true  } },
            { HystID::TubusTypeCell4, { "cell4Tubus",     "", Record(HystID::TubusTypeCell4, SCDefs::defUCharData ), true  } },
            { HystID::HeightTubus,    { "tubusHeight",    "", Record(HystID::HeightTubus,    SCDefs::defIntData   ), true  } },
            { HystID::HeightWeights,  { "weightsHeight",  "", Record(HystID::HeightWeights,  SCDefs::defIntData   ), true  } },
            { HystID::ExpenseReset,   { "expenseReset",   "", Record(HystID::ExpenseReset,   SCDefs::defBoolData  ), false } },
            { HystID::DeficitReset,   { "deficitReset",   "", Record(HystID::DeficitReset,   SCDefs::defBoolData  ), false } },
            { HystID::Start,          { "launch",         "", Record(HystID::Start,          SCDefs::defBoolData  ), false } },
            { HystID::VolumeLevel,    { "volumeLevel",    "", Record(HystID::VolumeLevel,    SCDefs::defUCharData ), true  } },
            { HystID::Voice,          { "voice",          "", Record(HystID::Voice,          SCDefs::defUCharData ), true  } },
            { HystID::FailureCode,    { "failureCode",    "", Record(HystID::FailureCode,    SCDefs::defUCharData ), false } },
            { HystID::HalfDeficitWrn, { "halfDeficitWrn", "", Record(HystID::HalfDeficitWrn, SCDefs::defBoolData  ), false } },
            { HystID::ProfileID,      { "profileId",      "", Record(HystID::ProfileID,      SCDefs::defUIntData  ), false } }
        }
    },
    {
        SCDefs::DeviceTypes::LIGHTSOURCE, {
            { LightSourceID::Power,               { "power",              "", Record(LightSourceID::Power,               SCDefs::defBoolData  ), true  } },
            { LightSourceID::PowerSet,            { "powerSet",           "", Record(LightSourceID::PowerSet,            SCDefs::defUCharData ), true  } },
            { LightSourceID::PowerMeas,           { "powerMeas",          "", Record(LightSourceID::PowerMeas,           SCDefs::defUCharData ), false } },
            { LightSourceID::VideoOn,             { "videoOn",            "", Record(LightSourceID::VideoOn,             SCDefs::defBoolData  ), true  } },
            { LightSourceID::VolumeLevel,         { "volumeLevel",        "", Record(LightSourceID::VolumeLevel,         SCDefs::defUCharData ), true  } },
            { LightSourceID::Voice,               { "voice",              "", Record(LightSourceID::Voice,               SCDefs::defUCharData ), true  } },
            { LightSourceID::FailureNoLightGuide, { "failureNoLighGuide", "", Record(LightSourceID::FailureNoLightGuide, SCDefs::defUCharData ), false } }
        }
    },
    {
        SCDefs::DeviceTypes::MEDINTABLE, {
            { MedinTableID::Power,                { "power",                "", Record(MedinTableID::Power,                SCDefs::defBoolData), true  } },
            { MedinTableID::Revers,               { "revers",               "", Record(MedinTableID::Revers,               SCDefs::defBoolData), true  } },
            { MedinTableID::Model,                { "model",                "", Record(MedinTableID::Model,                SCDefs::defUIntData), false } },
            { MedinTableID::PultChargeLow,        { "pultChargeLow",        "", Record(MedinTableID::PultChargeLow,        SCDefs::defBoolData), false } },
            { MedinTableID::ChargeCode,           { "chargeCode",           "", Record(MedinTableID::ChargeCode,           SCDefs::defUIntData), false } },
            { MedinTableID::FlagCharging,         { "flagCharging",         "", Record(MedinTableID::FlagCharging,         SCDefs::defBoolData), false } },
            { MedinTableID::FlagChargeLow,        { "flagChargeLow",        "", Record(MedinTableID::FlagChargeLow,        SCDefs::defBoolData), false } },
            { MedinTableID::FlagWorkMode,         { "flagWorkMode",         "", Record(MedinTableID::FlagWorkMode,         SCDefs::defBoolData), false } },
            { MedinTableID::FlagPressure,         { "flagPressure",         "", Record(MedinTableID::FlagPressure,         SCDefs::defBoolData), false } },
            { MedinTableID::FlagMovementsBlocked, { "flagMovementsBlocked", "", Record(MedinTableID::FlagMovementsBlocked, SCDefs::defBoolData), false } },
            { MedinTableID::FlagPositionOnEdge,   { "flagPositionOnEdge",   "", Record(MedinTableID::FlagPositionOnEdge,   SCDefs::defBoolData), false } },
            { MedinTableID::FlagPositionOnZero,   { "flagPositionOnZero",   "", Record(MedinTableID::FlagPositionOnZero,   SCDefs::defBoolData), false } },
            { MedinTableID::FlagPositionOnM1,     { "flagPositionOnM1",     "", Record(MedinTableID::FlagPositionOnM1,     SCDefs::defBoolData), false } },
            { MedinTableID::FlagPositionOnM2,     { "flagPositionOnM2",     "", Record(MedinTableID::FlagPositionOnM2,     SCDefs::defBoolData), false } },
            { MedinTableID::Trend,                { "trend",                "", Record(MedinTableID::Trend,                SCDefs::defUIntData), false } },
            { MedinTableID::Pillars,              { "pillars",              "", Record(MedinTableID::Pillars,              SCDefs::defBoolData), false } },
            { MedinTableID::Position,             { "position",             "", Record(MedinTableID::Position,             SCDefs::defUIntData), true  } },
            { MedinTableID::PositionSave,         { "positionSave",         "", Record(MedinTableID::PositionSave,         SCDefs::defUIntData), false } },
            { MedinTableID::Move,                 { "move",                 "", Record(MedinTableID::Move,                 SCDefs::defUIntData), false } },
            { MedinTableID::Shift,                { "shift",                "", Record(MedinTableID::Shift,                SCDefs::defUIntData), false } },
            { MedinTableID::Tilt,                 { "tilt",                 "", Record(MedinTableID::Tilt,                 SCDefs::defUIntData), false } },
            { MedinTableID::TiltBack,             { "tiltBack",             "", Record(MedinTableID::TiltBack,             SCDefs::defUIntData), false } },
            { MedinTableID::MoveRenalRoller,      { "moveRenalRoller",      "", Record(MedinTableID::MoveRenalRoller,      SCDefs::defUIntData), false } }
        }
    }
};
