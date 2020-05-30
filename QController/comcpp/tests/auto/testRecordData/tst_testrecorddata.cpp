#include <QtTest>

#include "smartcontrol/record.h"
#include "smartcontrol/scdefs.h"

Q_DECLARE_METATYPE(std::string)

class TestRecordData : public QObject
{
    Q_OBJECT

public:

private slots:
    void test_from20bytes();
    void test_from20bytes_data();
    void test_fromIdAnd18bytes();
    void test_fromIdAnd18bytes_data();

};

void TestRecordData::test_from20bytes()
{
    QFETCH(QByteArray, input);
    QFETCH(uint16_t, id);
    QFETCH(SCDefs::DataTypes, type);
    QFETCH(uint32_t, value);
    QFETCH(uint32_t, min);
    QFETCH(uint32_t, max);
    QFETCH(uint32_t, step);
    QFETCH(SCDefs::Units, unit);

    Record::Data data(input.data());
    QCOMPARE(id, data.fields.id);
    QCOMPARE(type, data.fields.type);
    QCOMPARE(value, static_cast<uint32_t>(data.fields.value));
    QCOMPARE(min,   static_cast<uint32_t>(data.fields.min));
    QCOMPARE(max,   static_cast<uint32_t>(data.fields.max));
    QCOMPARE(step,  static_cast<uint32_t>(data.fields.step));
    QCOMPARE(unit, data.fields.unit);
}

void TestRecordData::test_from20bytes_data()
{
    QTest::addColumn<QByteArray>("input");
    QTest::addColumn<uint16_t>("id");
    QTest::addColumn<SCDefs::DataTypes>("type");
    QTest::addColumn<uint32_t>("value");
    QTest::addColumn<uint32_t>("min");
    QTest::addColumn<uint32_t>("max");
    QTest::addColumn<uint32_t>("step");
    QTest::addColumn<SCDefs::Units>("unit");

    QTest::newRow("1 byte id")
        << QByteArray("\x0C\x00\x07\x00\x00\x00\x00\x00\x00\x00\x00\x14\x00\x00\x00\x01\x00\x00\x00\x01",20)
        << uint16_t(12)
        << SCDefs::DataTypes::UINT
        << uint32_t(0)
        << uint32_t(0)
        << uint32_t(20)
        << uint32_t(1)
        << SCDefs::Units::Percents;
    QTest::newRow("2 bytes id and fields")
        << QByteArray("\xE8\x03\x07\xE8\x03\x00\x00\xF4\x01\x00\x00\xD0\x07\x00\x00\x64\x00\x00\x00\x01",20)
        << uint16_t(1000)
        << SCDefs::DataTypes::UINT
        << uint32_t(1000)
        << uint32_t(500)
        << uint32_t(2000)
        << uint32_t(100)
        << SCDefs::Units::Percents;
}

void TestRecordData::test_fromIdAnd18bytes()
{
    QFETCH(QByteArray, input);
    QFETCH(uint16_t, id);
    QFETCH(SCDefs::DataTypes, type);
    QFETCH(uint32_t, value);
    QFETCH(uint32_t, min);
    QFETCH(uint32_t, max);
    QFETCH(uint32_t, step);
    QFETCH(SCDefs::Units, unit);

    Record::Data data(id, input.data());
    QCOMPARE(id, data.fields.id);
    QCOMPARE(type, data.fields.type);
    QCOMPARE(value, static_cast<uint32_t>(data.fields.value));
    QCOMPARE(min,   static_cast<uint32_t>(data.fields.min));
    QCOMPARE(max,   static_cast<uint32_t>(data.fields.max));
    QCOMPARE(step,  static_cast<uint32_t>(data.fields.step));
    QCOMPARE(unit, data.fields.unit);
}

void TestRecordData::test_fromIdAnd18bytes_data()
{
    QTest::addColumn<QByteArray>("input");
    QTest::addColumn<uint16_t>("id");
    QTest::addColumn<SCDefs::DataTypes>("type");
    QTest::addColumn<uint32_t>("value");
    QTest::addColumn<uint32_t>("min");
    QTest::addColumn<uint32_t>("max");
    QTest::addColumn<uint32_t>("step");
    QTest::addColumn<SCDefs::Units>("unit");

    QTest::newRow("1 byte id")
        << QByteArray("\x07\x00\x00\x00\x00\x00\x00\x00\x00\x14\x00\x00\x00\x01\x00\x00\x00\x01",18)
        << uint16_t(12)
        << SCDefs::DataTypes::UINT
        << uint32_t(0)
        << uint32_t(0)
        << uint32_t(20)
        << uint32_t(1)
        << SCDefs::Units::Percents;
    QTest::newRow("2 bytes id and fields")
        << QByteArray("\x07\xE8\x03\x00\x00\xF4\x01\x00\x00\xD0\x07\x00\x00\x64\x00\x00\x00\x01",18)
        << uint16_t(1000)
        << SCDefs::DataTypes::UINT
        << uint32_t(1000)
        << uint32_t(500)
        << uint32_t(2000)
        << uint32_t(100)
        << SCDefs::Units::Percents;
}

QTEST_APPLESS_MAIN(TestRecordData)
#include "tst_testrecorddata.moc"
