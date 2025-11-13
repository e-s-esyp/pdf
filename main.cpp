#include <QApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQuickItem>
#include <QMetaProperty>
#include <QDebug>
#include <QQmlProperty>

class PropertyLister final : public QObject
{
    Q_OBJECT
public:
    explicit PropertyLister(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE static QString listProperties(QQuickItem *item) {
        if (!item) return "Object is null";

        const QMetaObject *meta = item->metaObject();
        QStringList propertiesList;

        for (int i = 0; i < meta->propertyCount(); ++i) {
            QMetaProperty property = meta->property(i);
            const char* name = property.name();
            QVariant value = item->property(name);
            propertiesList << QString("%1: %2").arg(name).arg(value.toString());
        }
        return propertiesList.join(", ");
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    // engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    engine.load(QUrl(QStringLiteral("../main.qml")));
    const QObject *rootObject = engine.rootObjects().first();
    const QObject *button = rootObject->findChild<QObject*>("submitButton");
    if (button) {
        // Метод 1: Использование QObject::property()
        const QVariant buttonText = button->property("text");
        QVariant backgroundColor = button->property("color"); // Может не сработать для цвета фона

        qDebug() << "Текст кнопки:" << buttonText.toString();

        // Метод 2: Использование QQmlProperty::read()
        QVariant textValue = QQmlProperty::read(button, "text");
        qDebug() << "Текст кнопки (через QQmlProperty):" << textValue.toString();
    }
    return QApplication::exec();
}