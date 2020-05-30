#include "scdefs.h"

const QHash<SCDefs::Units, QString> SCDefs::mUnits = {
    {SCDefs::Units::UNITLESS,""},
    {SCDefs::Units::Percents,"%"},
    {SCDefs::Units::mmRtSt,"мм.рт.ст."},
    {SCDefs::Units::mL,"мл"},
    {SCDefs::Units::L,"л"},
    {SCDefs::Units::mLperMin,"мл/мин"},
    {SCDefs::Units::LperMin,"л/мин"},
    {SCDefs::Units::RotationsPerMin,"об/мин"},
    {SCDefs::Units::Hz,"Гц"},
    {SCDefs::Units::Pa,"Па"},
    {SCDefs::Units::kPa,"кПа"},
    {SCDefs::Units::MPa,"МПа"},
    {SCDefs::Units::mW,"мВт"},
    {SCDefs::Units::W,"Вт"},
    {SCDefs::Units::mA,"мА"},
    {SCDefs::Units::A,"А"},
    {SCDefs::Units::sm,"см"},
    {SCDefs::Units::V,"В"},
    {SCDefs::Units::s,"с"},
    {SCDefs::Units::ms,"мс"},
    {SCDefs::Units::Ohm,"Ом"},
};

const QMap<SCDefs::DeviceTypes, QString> SCDefs::mUuids = {
    {SCDefs::DeviceTypes::HysteroPump,"Гистеропомпа"},
    {SCDefs::DeviceTypes::ESU,"ЭХВЧ"},
    {SCDefs::DeviceTypes::INSUF,"Инсуффлятор"},
    {SCDefs::DeviceTypes::ASPIRR,"Аспиратор-ирригатор"},
    {SCDefs::DeviceTypes::LIGHTSOURCE,"Осветитель"},
    {SCDefs::DeviceTypes::MEDINTABLE,"Стол Медин"}
};

// Failure messages
const QMap<SCDefs::DeviceTypes, QHash<uint8_t, QString>> SCDefs::mFailMsgs = {
    {SCDefs::DeviceTypes::HysteroPump,
     {
         {0,""},
         {1,"Авария Н.1"},
         {2,"Авария Н.2"},
         {3,"Давление более 250 мм.рт.ст."},
         {4,"Поток более 0.6 л/мин"},
         {5,"Превышен критический расход"},
         {6,"Превышен критический дефицит"},
         {7,"Высокая скорость нарастания дефицита"}
     }
    },
    {SCDefs::DeviceTypes::ESU,
     {
         {0,""}
     }
    },
    {SCDefs::DeviceTypes::INSUF,
     {
         {0,""},
         {1,"Авария Н.1"},
         {2,"Отсутствует углекислый газ на входе Инсуффлятора"},
         {3,"Повышенное ВД"},
         {4,"Обрыв"},
         {5,"Пережим"},
         {6,"Избыточное давление"},
         {7,"Разрежение"}
     }
    },
    {SCDefs::DeviceTypes::ASPIRR,
     {
         {0,""},
         {1,"Перегрев"},
         {2,"Переполнение"},
         {3,"Негерметичен канал Аспирации"}
     }
    },
    {SCDefs::DeviceTypes::LIGHTSOURCE,
     {
         {0,""},
         {1,"Нет световодного кабеля"}
     }
    },
    {SCDefs::DeviceTypes::MEDINTABLE,
     {
         {0,""}
     }
    }
};

const char SCDefs::defBoolData[18] = {DataTypes::BOOL,
                                      0x00,0x00,0x00,0x00, // value
                                      0x00,0x00,0x00,0x00, // min
                                      0x00,0x00,0x00,0x00, // max
                                      0x00,0x00,0x00,0x00, // step
                                      Units::UNITLESS};

const char SCDefs::defCharData[18] = {DataTypes::CHAR,
                                      0x00,0x00,0x00,0x00, // value
                                      0x00,0x00,0x00,0x00, // min
                                      0x00,0x00,0x00,0x00, // max
                                      0x00,0x00,0x00,0x00, // step
                                      Units::UNITLESS};

const char SCDefs::defUCharData[18] = {DataTypes::UCHAR,
                                       0x00,0x00,0x00,0x00, // value
                                       0x00,0x00,0x00,0x00, // min
                                       0x00,0x00,0x00,0x00, // max
                                       0x00,0x00,0x00,0x00, // step
                                       Units::UNITLESS};

const char SCDefs::defShortData[18] = {DataTypes::SHORT,
                                       0x00,0x00,0x00,0x00, // value
                                       0x00,0x00,0x00,0x00, // min
                                       0x00,0x00,0x00,0x00, // max
                                       0x00,0x00,0x00,0x00, // step
                                       Units::UNITLESS};

const char SCDefs::defUShortData[18] = {DataTypes::UCHAR,
                                        0x00,0x00,0x00,0x00, // value
                                        0x00,0x00,0x00,0x00, // min
                                        0x00,0x00,0x00,0x00, // max
                                        0x00,0x00,0x00,0x00, // step
                                        Units::UNITLESS};

const char SCDefs::defIntData[18] = {DataTypes::INT,
                                     0x00,0x00,0x00,0x00, // value
                                     0x00,0x00,0x00,0x00, // min
                                     0x00,0x00,0x00,0x00, // max
                                     0x00,0x00,0x00,0x00, // step
                                     Units::UNITLESS};

const char SCDefs::defUIntData[18] = {DataTypes::UINT,
                                      0x00,0x00,0x00,0x00, // value
                                      0x00,0x00,0x00,0x00, // min
                                      0x00,0x00,0x00,0x00, // max
                                      0x00,0x00,0x00,0x00, // step
                                      Units::UNITLESS};

const char SCDefs::defLongData[18] = {DataTypes::LONG,
                                         0x00,0x00,0x00,0x00, // value
                                         0x00,0x00,0x00,0x00, // min
                                         0x00,0x00,0x00,0x00, // max
                                         0x00,0x00,0x00,0x00, // step
                                         Units::UNITLESS};

const char SCDefs::defULongData[18] = {DataTypes::ULONG,
                                       0x00,0x00,0x00,0x00, // value
                                       0x00,0x00,0x00,0x00, // min
                                       0x00,0x00,0x00,0x00, // max
                                       0x00,0x00,0x00,0x00, // step
                                       Units::UNITLESS};

const char SCDefs::defLongLongData[18] = {DataTypes::LONGLONG,
                                          0x00,0x00,0x00,0x00, // value
                                          0x00,0x00,0x00,0x00, // min
                                          0x00,0x00,0x00,0x00, // max
                                          0x00,0x00,0x00,0x00, // step
                                          Units::UNITLESS};

const char SCDefs::defULongLongData[18] = {DataTypes::ULONGLONG,
                                           0x00,0x00,0x00,0x00, // value
                                           0x00,0x00,0x00,0x00, // min
                                           0x00,0x00,0x00,0x00, // max
                                           0x00,0x00,0x00,0x00, // step
                                           Units::UNITLESS};

const char SCDefs::defFloatData[18] = {DataTypes::FLOAT,
                                       0x00,0x00,0x00,0x00, // value
                                       0x00,0x00,0x00,0x00, // min
                                       0x00,0x00,0x00,0x00, // max
                                       0x00,0x00,0x00,0x00, // step
                                       Units::UNITLESS};

const char SCDefs::defDoubleData[18] = {DataTypes::DOUBLE,
                                        0x00,0x00,0x00,0x00, // value
                                        0x00,0x00,0x00,0x00, // min
                                        0x00,0x00,0x00,0x00, // max
                                        0x00,0x00,0x00,0x00, // step
                                        Units::UNITLESS};

const char SCDefs::defUCharArrayData[18] = {DataTypes::UCHARARRAY,
                                            0x00,0x00,0x00,0x00, // value
                                            0x00,0x00,0x00,0x00, // min
                                            0x00,0x00,0x00,0x00, // max
                                            0x00,0x00,0x00,0x00, // step
                                            Units::UNITLESS};

const QByteArray SCDefs::getDefaultData(SCDefs::DataTypes type)
{
    switch (type) {
    case SCDefs::DataTypes::BOOL:
        return QByteArray(reinterpret_cast<const char *>(defBoolData),       18);
    case SCDefs::DataTypes::CHAR:
        return QByteArray(reinterpret_cast<const char *>(defCharData),       18);
    case SCDefs::DataTypes::UCHAR:
        return QByteArray(reinterpret_cast<const char *>(defUCharData),      18);
    case SCDefs::DataTypes::SHORT:
        return QByteArray(reinterpret_cast<const char *>(defShortData),      18);
    case SCDefs::DataTypes::USHORT:
        return QByteArray(reinterpret_cast<const char *>(defUShortData),     18);
    case SCDefs::DataTypes::INT:
        return QByteArray(reinterpret_cast<const char *>(defIntData),        18);
    case SCDefs::DataTypes::LONG:
        return QByteArray(reinterpret_cast<const char *>(defLongData),       18);
    case SCDefs::DataTypes::UINT:
        return QByteArray(reinterpret_cast<const char *>(defUIntData),       18);
    case SCDefs::DataTypes::ULONG:
        return QByteArray(reinterpret_cast<const char *>(defULongData),      18);
    case SCDefs::DataTypes::LONGLONG:
        return QByteArray(reinterpret_cast<const char *>(defLongLongData),   18);
    case SCDefs::DataTypes::ULONGLONG:
        return QByteArray(reinterpret_cast<const char *>(defULongLongData),  18);
    case SCDefs::DataTypes::FLOAT:
        return QByteArray(reinterpret_cast<const char *>(defFloatData),      18);
    case SCDefs::DataTypes::DOUBLE:
        return QByteArray(reinterpret_cast<const char *>(defDoubleData),     18);
    case SCDefs::DataTypes::UCHARARRAY:
        return QByteArray(reinterpret_cast<const char *>(defUCharArrayData), 18);
    }
    return QByteArray(reinterpret_cast<const char *>(defBoolData),       18);
}
