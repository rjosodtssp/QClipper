﻿#ifndef QCLIPPER_H
#define QCLIPPER_H

#include <QDialog>
#include <QClipboard>
#include <QVector>
#include <QListWidgetItem>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QTextStream>
#include <QFile>
#include <QPointer>
#include <qxtglobalshortcut.h>
#include <QMessageBox>
#include <QUndoStack>
#include <QPropertyAnimation>

#include <template.h>
#include <setting.h>
#include <savecmd.h>

namespace Ui {
class QClipper;
}

class QClipper : public QDialog
{
    Q_OBJECT

public:
    explicit QClipper(QWidget *parent = 0);
    ~QClipper();

private:
    void InitUi();
    void SetTray();
    void SetShortCut();
    void StartAnimation(QRect begin, QRect end);
private:
    Ui::QClipper *ui;

    QVector<QString> v;
    QClipboard* board;
    QFont* font;
    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;
    QxtGlobalShortcut* shortcut, WakeUp, Mini;
    bool hasText;

    QString MultiText;
    QFile* f;

    int count;
    Template* tem;
//    QPointer<Setting> m_setting;
    Setting* m_setting;
    bool m_CheckSame;
    bool m_MultiSel;
    bool m_show;
    bool m_KeepMin;
    qreal opacity;

    QString minimize;
    QString wakeup;

    QMenu menu;
    QMenu *m=NULL;
    QFile* StoredFile;
    QString saveText;
    QStringList loadText;
    QUndoStack *undoStack;
    QPropertyAnimation *animation;

    enum{
        MAX_ROW = 10,
        FONT_SIZE = 24,
        WIDTH = 320,
        HEIGHT = 300,
        FILTER_H = 35,
        W = WIDTH*2+5,
        H = HEIGHT+5+FILTER_H,
        ANIMATION_TIME=200
    };
private slots:
    void addText();
    void ClickText();
    void LoadSaveText();

    void SetAutoRun(bool on);

    bool IsBlank(QString text);

    void on_list_customContextMenuRequested(const QPoint &pos);

    void LoadChildMenu();

    void ReadTheme();

    void on_Clear_triggered();

    void on_Setting_triggered();

    void Export();

    void on_About_QClipper_triggered();

    void TrayIconClicked(QSystemTrayIcon::ActivationReason reason);

    void on_ShowNormal_triggered();
    void on_ShowMini();

    void on_Exit_triggered();

    void on_filter_textChanged(const QString &arg1);

    void on_AddTemplate_triggered();

    void on_Save_triggered();

    void on_clearMult_triggered();

    void on_Reboot_triggered();

    void on_Undo_triggered();

    void on_Help_triggered();

    void on_Close_triggered();

    void on_Delete_triggered();

    void on_stored_customContextMenuRequested(const QPoint &pos);

protected:
    void changeEvent(QEvent *e);
    bool eventFilter(QObject *obj, QEvent *e);
};

#endif // QCLIPPER_H
