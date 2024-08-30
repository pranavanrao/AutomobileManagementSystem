#ifndef AUTOCATEGORIES_H
#define AUTOCATEGORIES_H

#include <QObject>
#include <QJsonObject>

class AutoCategories : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QPair<QString, QString> > mainCategories READ mainCategories WRITE setMainCategories NOTIFY mainCategoriesChanged FINAL)

public:
    explicit AutoCategories(QObject *parent = nullptr);

    void initializeFromJson(const QJsonObject jsonObject);
    void printMainCategories() const;

    QList<QPair<QString, QString> > mainCategories() const;
    void setMainCategories(const QList<QPair<QString, QString> > &newMainCategories);

signals:
    void mainCategoriesChanged();

private:
    QList<QPair<QString, QString>> m_mainCategories;
};

#endif // AUTOCATEGORIES_H
