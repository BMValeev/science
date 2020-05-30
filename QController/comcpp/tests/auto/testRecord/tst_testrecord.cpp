#include <QtTest>
#include <QDataStream>
#include <QSettings>

#include "smartcontrol/record.h"

Q_DECLARE_METATYPE(std::string)

class TestRecord : public QObject
{
    Q_OBJECT

public:
    TestRecord();

private slots:
    void test_from20bytes();
    void test_from20bytes_data();
    void test_fromIdAnd18bytes();
    void test_fromIdAnd18bytes_data();
    void test_qt_serializing();
    void test_qt_serializing_data();
    void test_qsettings();
    void test_qsettings_data();
};

TestRecord::TestRecord()
{
    qRegisterMetaType<Record>("Record");
    qRegisterMetaTypeStreamOperators<Record>("Record");
}

void TestRecord::test_from20bytes()
{
    QFETCH(QByteArray, input);
    QFETCH(uint16_t, id);
    QFETCH(SCDefs::DataTypes, type);
    QFETCH(uint32_t, value);
    QFETCH(uint32_t, min);
    QFETCH(uint32_t, max);
    QFETCH(uint32_t, step);
    QFETCH(SCDefs::Units, unit);

    Record record(input.data());
    QCOMPARE(id, record.id());
    QCOMPARE(type, record.type());
    QCOMPARE(value, record.value<uint32_t>());
    QCOMPARE(min,   record.min<uint32_t>());
    QCOMPARE(max,   record.max<uint32_t>());
    QCOMPARE(step,  record.step<uint32_t>());
    QCOMPARE(unit, record.unit());
}

void TestRecord::test_from20bytes_data()
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

void TestRecord::test_fromIdAnd18bytes()
{
    QFETCH(QByteArray, input);
    QFETCH(uint16_t, id);
    QFETCH(SCDefs::DataTypes, type);
    QFETCH(uint32_t, value);
    QFETCH(uint32_t, min);
    QFETCH(uint32_t, max);
    QFETCH(uint32_t, step);
    QFETCH(SCDefs::Units, unit);

    Record record(id, input.data());
    QCOMPARE(id, record.id());
    QCOMPARE(type, record.type());
    QCOMPARE(value, record.value<uint32_t>());
    QCOMPARE(min,   record.min<uint32_t>());
    QCOMPARE(max,   record.max<uint32_t>());
    QCOMPARE(step,  record.step<uint32_t>());
    QCOMPARE(unit, record.unit());
}

void TestRecord::test_fromIdAnd18bytes_data()
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

void TestRecord::test_qt_serializing()
{
    QFETCH(QByteArray, input);

    Record rInput(input.data());
    Record rOutput;

    QByteArray a;
    QDataStream s(&a, QIODevice::ReadWrite);

    s << rInput;
    s.device()->reset();
    s >> rOutput;

    QCOMPARE(rInput.id(),              rOutput.id());
    QCOMPARE(rInput.type(),            rOutput.type());
    QCOMPARE(rInput.value<uint32_t>(), rOutput.value<uint32_t>());
    QCOMPARE(rInput.min<uint32_t>(),   rOutput.min<uint32_t>());
    QCOMPARE(rInput.max<uint32_t>(),   rOutput.max<uint32_t>());
    QCOMPARE(rInput.step<uint32_t>(),  rOutput.step<uint32_t>());
    QCOMPARE(rInput.unit(),            rOutput.unit());

}

void TestRecord::test_qt_serializing_data()
{
    QTest::addColumn<QByteArray>("input");

    QTest::newRow("1 byte id")
        << QByteArray("\x0C\x00\x07\x00\x00\x00\x00\x00\x00\x00\x00\x14\x00\x00\x00\x01\x00\x00\x00\x01",20);
    QTest::newRow("2 bytes id and fields")
            << QByteArray("\xE8\x03\x07\xE8\x03\x00\x00\xF4\x01\x00\x00\xD0\x07\x00\x00\x64\x00\x00\x00\x01",20);
}

void TestRecord::test_qsettings()
{
    QFETCH(QByteArray, input);

    Record rInput(input.data());

    QSettings s;
    s.setValue("record", QVariant::fromValue(rInput));
    Record rOutput = s.value("record").value<Record>();

    QCOMPARE(rInput.id(),              rOutput.id());
    QCOMPARE(rInput.type(),            rOutput.type());
    QCOMPARE(rInput.value<uint32_t>(), rOutput.value<uint32_t>());
    QCOMPARE(rInput.min<uint32_t>(),   rOutput.min<uint32_t>());
    QCOMPARE(rInput.max<uint32_t>(),   rOutput.max<uint32_t>());
    QCOMPARE(rInput.step<uint32_t>(),  rOutput.step<uint32_t>());
    QCOMPARE(rInput.unit(),            rOutput.unit());
}

void TestRecord::test_qsettings_data()
{
    QTest::addColumn<QByteArray>("input");

    QTest::newRow("1 byte id")
        << QByteArray("\x0C\x00\x07\x00\x00\x00\x00\x00\x00\x00\x00\x14\x00\x00\x00\x01\x00\x00\x00\x01",20);
    QTest::newRow("2 bytes id and fields")
            << QByteArray("\xE8\x03\x07\xE8\x03\x00\x00\xF4\x01\x00\x00\xD0\x07\x00\x00\x64\x00\x00\x00\x01",20);
}

QTEST_APPLESS_MAIN(TestRecord)
#include "tst_testrecord.moc"
