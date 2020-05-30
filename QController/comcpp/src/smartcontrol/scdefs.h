#ifndef SCDEFS_H
#define SCDEFS_H

#include <QObject>
#include <QHash>
#include <QMap>

class SCDefs
{
    Q_GADGET
    //Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")

public:
    // Records data types
    enum DataTypes: uint8_t {
        BOOL       = 1,
        CHAR       = 2,
        UCHAR      = 3,
        SHORT      = 4,
        USHORT     = 5,
        INT        = 6,
        UINT       = 7,
        LONG       = 8,
        ULONG      = 9,
        LONGLONG   = 10,
        ULONGLONG  = 11,
        FLOAT      = 12,
        DOUBLE     = 13,
        UCHARARRAY = 14
    };
    Q_ENUM(DataTypes)

    // Records units
    enum Units: uint8_t {
        UNITLESS = 0x00,
        Percents,
        mmRtSt,
        mL,
        L,
        mLperMin,
        LperMin,
        RotationsPerMin,
        Hz,
        Pa,
        kPa,
        MPa,
        mW,
        W,
        mA,
        A,
        sm,
        V,
        s,
        ms,
        Ohm
    };
    Q_ENUM(Units)

    enum class DeviceTypes {
        Unknown     = 0x00,
        HysteroPump = 0x01,
        ESU         = 0x02,
        INSUF       = 0x03,
        ASPIRR      = 0x04,
        LIGHTSOURCE = 0x05,
        MEDINTABLE  = 0x06,
        KOREA_CAMERA=0x07
    };
    Q_ENUM(DeviceTypes)

    static const char defBoolData[18];
    static const char defCharData[18];
    static const char defUCharData[18];
    static const char defShortData[18];
    static const char defUShortData[18];
    static const char defIntData[18];
    static const char defUIntData[18];
    static const char defLongData[18];
    static const char defULongData[18];
    static const char defLongLongData[18];
    static const char defULongLongData[18];
    static const char defFloatData[18];
    static const char defDoubleData[18];
    static const char defUCharArrayData[18];

    static QString getUnitsAsString(SCDefs::Units unit) {
        return mUnits.value(unit,"");
    }

    static QString getUuidAsString(SCDefs::DeviceTypes type) {
        return mUuids.value(type, "Неизвестное устройство");
    }

    static QString getFailureAsString(SCDefs::DeviceTypes type, uint8_t failureCode) {
        return mFailMsgs.value(type, QHash<uint8_t,QString>()).value(failureCode,"");
    }

    static const QByteArray getDefaultData(SCDefs::DataTypes type);

private:
    static const QHash<SCDefs::Units, QString> mUnits;
    static const QMap<SCDefs::DeviceTypes, QString> mUuids;
    static const QMap<SCDefs::DeviceTypes, QHash<uint8_t,QString>> mFailMsgs;
};
Q_DECLARE_METATYPE(SCDefs::DeviceTypes)

class HystID
{
public:
    enum uint16_t {
        PressureSet    = 1,
        PressureMeas   = 2,
        FlowSet        = 3,
        FlowMeas       = 4,
        ExpenseCrit    = 5,
        ExpenseMeas    = 6,
        DeficitCrit    = 7,
        DeficitMeas    = 8,
        TubusCell      = 9,
        TubusTypeCell1 = 10,
        TubusTypeCell2 = 11,
        TubusTypeCell3 = 12,
        TubusTypeCell4 = 13,
        HeightTubus    = 14,
        HeightWeights  = 15,
        ExpenseReset   = 16,
        DeficitReset   = 17,
        Power          = 18,
        Start          = 19,
        VolumeLevel    = 20,
        Voice          = 21,
        FailureCode    = 22,
        HalfDeficitWrn = 23,
        ProfileID      = 1000
    };
};

class InsufID
{
public:
    enum uint16_t {
        PressureInput        = 1,
        PressureSet          = 2,
        PressureMeas         = 3,
        ExpenseSet           = 4,
        ExpenseMeas          = 5,
        VolumeMeas           = 6,
        VolumeReset          = 7,
        SpeedUp              = 8,
        Power                = 9,
        GasOn                = 10,
        VolumeLevel          = 11,
        Voice                = 12,
        FailureCode          = 13,
        UnderpressureWrn     = 14,
        InsufflationPressure = 101,
        InsufflationExpense  = 102,
        GasType              = 103,
        WDSensorType         = 104,
        WDZero               = 105,
        PressureSensorZero   = 106,
        ExpenseSensorZero    = 107,
        KlapanZero           = 108,
        KlapanOffset         = 109,
        KlapanTilt           = 110,
        ConfigBlock          = 111,
        ProfileID            = 1000
    };
};

class LightSourceID
{
public:
    enum uint16_t {
        Power               = 1,
        PowerSet            = 2,
        PowerMeas           = 3,
        VideoOn             = 4,
        VolumeLevel         = 5,
        Voice               = 6,
        FailureNoLightGuide = 7
    };
};

class ESUID
{
public:
    enum uint16_t {
        Power                = 1,
        FailureCode          = 2,
        VolumeLevel          = 3,
        Language             = 4,
        MaxActivationTime    = 5,
        IrrigationControl    = 6,
        IrrigationStartDelay = 7,
        SocketActive         = 8,
        SocketExpanded       = 9,
        S1CutPower           = 10,
        S1CutEffect          = 11,
        S1CutMode            = 12,
        S1CoagPower          = 13,
        S1CoagEffect         = 14,
        S1CoagMode           = 15,
        S2CutPower           = 16,
        S2CutEffect          = 17,
        S2CutMode            = 18,
        S2CoagPower          = 19,
        S2CoagEffect         = 20,
        S2CoagMode           = 21,
        S3CutPower           = 22,
        S3CutEffect          = 23,
        S3CutMode            = 24,
        S3CoagPower          = 25,
        S3CoagEffect         = 26,
        S3CoagMode           = 27,
        AutostartDelay       = 28,
        AutostopResistance   = 29
    };
};

class AspiratorID
{
public:
    enum uint16_t {
        PressureSet       = 1,
        PressureMeas      = 2,
        UnderpressureSet  = 3,
        UnderpressureMeas = 4,
        VacReset          = 5,
        Auto              = 6,
        Power             = 7,
        VolumeLevel       = 8,
        Voice             = 9,
        FailureCode       = 10,
        ProfileID         = 1000
    };
};

class MedinTableID
{
public:
    enum uint16_t {
        Power = 0x01,
        Model,
        PultChargeLow,
        Revers,
        ChargeCode,
        FlagCharging,
        FlagChargeLow,
        FlagWorkMode,
        FlagPressure,
        FlagMovementsBlocked,
        FlagPositionOnEdge,
        FlagPositionOnZero,
        FlagPositionOnM1,
        FlagPositionOnM2,
        Trend,
        Pillars,
        Position,
        PositionSave,
        Move,
        Shift,
        Tilt,
        TiltBack,
        MoveRenalRoller
    };
};
class CameraID {
public:
    enum uint16_t {
        Power = 1,
        Model,
        Hue,
        Color,
        Sharp = 5,
        Bright,
        GammaValue,
        Contrast,
        GammaConfig,
        WhiteBalance= 10,
        WBRed,
        WBBlue,
        Exposition,
        AreaAnalysis,
        AreaRegion= 15,
        ImageParam,
        ImageRate,
        RecordQuality,
        RecordName,
        PhotoName= 20,
        RecordSize,
        ButtonConfig,
        VolumeLevel,
        Voice,
        Language,
        FailureCode= 25
    };
};
namespace Medin {
    Q_NAMESPACE
    //Q_CLASSINFO("RegisterEnumClassesUnscoped", "false")

enum Model {
    Theta = 1,
    Sigma,
    Beta,
    Delta
};
Q_ENUM_NS(Model)

enum Position {
    ZERO = 1,
    M1,
    M2
};
Q_ENUM_NS(Position)

enum Direction {
    NO_MOVE = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT
};
Q_ENUM_NS(Direction)

}

#endif // SCDEFS_H
