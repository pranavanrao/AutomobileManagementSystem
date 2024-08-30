#include "AutoCategories.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

AutoCategories::AutoCategories(QObject *parent)
    : QObject{parent}
{
    QString filename = ":/data/mainCategories.json";
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << Q_FUNC_INFO << "Failed to load the data file : " << filename;
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(jsonData));
    QJsonObject jsonObject = doc.object();

    initializeFromJson(jsonObject);
}

void AutoCategories::initializeFromJson(const QJsonObject json)
{
    QJsonArray mainCategoriesArray = json["mainCategories"].toArray();
    QList<QPair<QString, QString>> categories;
    for(const QJsonValue &value : mainCategoriesArray) {
        QJsonObject obj = value.toObject();
        QString mainCategory = obj["title"].toString();
        QString imagePath = obj["image"].toString();
        categories.append(qMakePair(mainCategory, imagePath));
    }
    setMainCategories(categories);
}

void AutoCategories::printMainCategories() const
{
    qDebug() << Q_FUNC_INFO << "All Main Categories:";
    for (const QPair<QString, QString> &category : m_mainCategories) {
        qDebug() << "Title:" << category.first << ", Image:" << category.second;
    }
}

QList<QPair<QString, QString> > AutoCategories::mainCategories() const
{
    return m_mainCategories;
}

void AutoCategories::setMainCategories(const QList<QPair<QString, QString> > &newMainCategories)
{
    if (m_mainCategories == newMainCategories)
        return;
    m_mainCategories = newMainCategories;
    emit mainCategoriesChanged();
}

QVariantList AutoCategories::parseMainCategories() const
{
    QVariantList list;
    for(const QPair<QString, QString> &category : m_mainCategories) {
        QVariantMap map;
        map["title"] = category.first;
        map["image"] = category.second;
        list.append(map);
    }
    return list;
}
