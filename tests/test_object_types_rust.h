/* generated by rust_qt_binding_generator */
#ifndef TEST_OBJECT_TYPES_RUST_H
#define TEST_OBJECT_TYPES_RUST_H

#include <QtCore/QObject>
#include <QtCore/QAbstractItemModel>

class Object;

class Object : public QObject
{
    Q_OBJECT
public:
    class Private;
private:
    Private * m_d;
    bool m_ownsPrivate;
    Q_PROPERTY(bool boolean READ boolean WRITE setBoolean NOTIFY booleanChanged FINAL)
    Q_PROPERTY(QByteArray bytearray READ bytearray WRITE setBytearray NOTIFY bytearrayChanged FINAL)
    Q_PROPERTY(float f32 READ f32 WRITE setF32 NOTIFY f32Changed FINAL)
    Q_PROPERTY(double f64 READ f64 WRITE setF64 NOTIFY f64Changed FINAL)
    Q_PROPERTY(qint16 i16 READ i16 WRITE setI16 NOTIFY i16Changed FINAL)
    Q_PROPERTY(qint32 i32 READ i32 WRITE setI32 NOTIFY i32Changed FINAL)
    Q_PROPERTY(qint64 i64 READ i64 WRITE setI64 NOTIFY i64Changed FINAL)
    Q_PROPERTY(qint8 i8 READ i8 WRITE setI8 NOTIFY i8Changed FINAL)
    Q_PROPERTY(QVariant optionalBoolean READ optionalBoolean WRITE setOptionalBoolean NOTIFY optionalBooleanChanged FINAL)
    Q_PROPERTY(QByteArray optionalBytearray READ optionalBytearray WRITE setOptionalBytearray NOTIFY optionalBytearrayChanged FINAL)
    Q_PROPERTY(QString optionalString READ optionalString WRITE setOptionalString NOTIFY optionalStringChanged FINAL)
    Q_PROPERTY(QVariant optionalU64 READ optionalU64 WRITE setOptionalU64 NOTIFY optionalU64Changed FINAL)
    Q_PROPERTY(QString string READ string WRITE setString NOTIFY stringChanged FINAL)
    Q_PROPERTY(QString stringByFunction READ stringByFunction WRITE setStringByFunction NOTIFY stringByFunctionChanged FINAL)
    Q_PROPERTY(quint16 u16 READ u16 WRITE setU16 NOTIFY u16Changed FINAL)
    Q_PROPERTY(quint32 u32 READ u32 WRITE setU32 NOTIFY u32Changed FINAL)
    Q_PROPERTY(quint64 u64 READ u64 WRITE setU64 NOTIFY u64Changed FINAL)
    Q_PROPERTY(quint8 u8 READ u8 WRITE setU8 NOTIFY u8Changed FINAL)
    explicit Object(bool owned, QObject *parent);
public:
    explicit Object(QObject *parent = nullptr);
    ~Object();
    bool boolean() const;
    void setBoolean(bool v);
    QByteArray bytearray() const;
    void setBytearray(const QByteArray& v);
    float f32() const;
    void setF32(float v);
    double f64() const;
    void setF64(double v);
    qint16 i16() const;
    void setI16(qint16 v);
    qint32 i32() const;
    void setI32(qint32 v);
    qint64 i64() const;
    void setI64(qint64 v);
    qint8 i8() const;
    void setI8(qint8 v);
    QVariant optionalBoolean() const;
    void setOptionalBoolean(const QVariant& v);
    QByteArray optionalBytearray() const;
    void setOptionalBytearray(const QByteArray& v);
    QString optionalString() const;
    void setOptionalString(const QString& v);
    QVariant optionalU64() const;
    void setOptionalU64(const QVariant& v);
    QString string() const;
    void setString(const QString& v);
    QString stringByFunction() const;
    void setStringByFunction(const QString& v);
    quint16 u16() const;
    void setU16(quint16 v);
    quint32 u32() const;
    void setU32(quint32 v);
    quint64 u64() const;
    void setU64(quint64 v);
    quint8 u8() const;
    void setU8(quint8 v);
Q_SIGNALS:
    void booleanChanged();
    void bytearrayChanged();
    void f32Changed();
    void f64Changed();
    void i16Changed();
    void i32Changed();
    void i64Changed();
    void i8Changed();
    void optionalBooleanChanged();
    void optionalBytearrayChanged();
    void optionalStringChanged();
    void optionalU64Changed();
    void stringChanged();
    void stringByFunctionChanged();
    void u16Changed();
    void u32Changed();
    void u64Changed();
    void u8Changed();
};
#endif // TEST_OBJECT_TYPES_RUST_H
