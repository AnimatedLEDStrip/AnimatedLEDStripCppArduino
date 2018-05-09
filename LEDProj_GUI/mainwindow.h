#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_mainwindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow//, public Ui_MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString getColorHex(const QString & arg1) {

        if (arg1 == "AliceBlue") {
            return "F0F8FF";
        } else if (arg1 == "Amethyst") {
            return "9966CC";
        } else if (arg1 == "AntiqueWhite") {
            return "FAEBD7";
        } else if (arg1 == "Aqua" || arg1 == "Cyan") {
            return "00FFFF";
        } else if (arg1 == "Aquamarine") {
            return "7FFFD4";
        } else if (arg1 == "Azure") {
            return "F0FFFF";
        } else if (arg1 == "Beige") {
            return "F5F5DC";
        } else if (arg1 == "Bisque") {
            return "FFE4C4";
        } else if (arg1 == "Black") {
            return "000000";
        } else if (arg1 == "BlanchedAlmond") {
            return "FFEBCD";
        } else if (arg1 == "Blue") {
            return "0000FF";
        } else if (arg1 == "BlueViolet") {
            return "8A2BE2";
        } else if (arg1 == "Brown") {
            return "A52A2A";
        } else if (arg1 == "BurlyWood") {
            return "DEB887";
        } else if (arg1 == "CadetBlue") {
            return "5F9EA0";
        } else if (arg1 == "Chartreuse") {
            return "7FFF00";
        } else if (arg1 == "Chocolate") {
            return "D2691E";
        } else if (arg1 == "Coral") {
            return "FF7F50";
        } else if (arg1 == "CornflowerBlue") {
            return "6495ED";
        } else if (arg1 == "Cornsilk") {
            return "FFF8DC";
        } else if (arg1 == "Crimson") {
            return "DC143C";
        } else if (arg1 == "DarkBlue") {
            return "00008B";
        } else if (arg1 == "DarkCyan") {
            return "008B8B";
        } else if (arg1 == "DarkGoldenrod") {
            return "B8860B";
        } else if (arg1 == "DarkGray" || arg1 == "DarkGrey") {
            return "A9A9A9";
        } else if (arg1 == "DarkGreen") {
            return "006400";
        } else if (arg1 == "DarkKhaki") {
            return "BDB76B";
        } else if (arg1 == "DarkMagenta") {
            return "8B008B";
        } else if (arg1 == "DarkOliveGreen") {
            return "556B2F";
        } else if (arg1 == "DarkOrange") {
            return "FF8C00";
        } else if (arg1 == "DarkOrchid") {
            return "9932CC";
        } else if (arg1 == "DarkRed") {
            return "8B0000";
        } else if (arg1 == "DarkSalmon") {
            return "E9967A";
        } else if (arg1 == "DarkSeaGreen") {
            return "8FBC8F";
        } else if (arg1 == "DarkSlateBlue") {
            return "483D8B";
        } else if (arg1 == "DarkSlateGray" || arg1 == "DarkSlateGray") {
            return "2F4F4F";
        } else if (arg1 == "DarkTurquoise") {
            return "00CED1";
        } else if (arg1 == "DarkViolet") {
            return "9400D3";
        } else if (arg1 == "DeepPink") {
            return "FF1493";
        } else if (arg1 == "DeepSkyBlue") {
            return "00BFFF";
        } else if (arg1 == "DimGray" || arg1 == "DimGrey") {
            return "696969";
        } else if (arg1 == "DodgerBlue") {
            return "1E90FF";
        } else if (arg1 == "FairyLight") {
            return "FFE42D";
        } else if (arg1 == "FairyLightNCC") {
            return "FF9D2A";
        } else if (arg1 == "FireBrick") {
            return "B22222";
        } else if (arg1 == "FloralWhite") {
            return "FFFAF0";
        } else if (arg1 == "ForestGreen") {
            return "228B22";
        } else if (arg1 == "Fuchsia" || arg1 == "Magenta") {
            return "FF00FF";
        } else if (arg1 == "Gainsboro") {
            return "DCDCDC";
        } else if (arg1 == "GhostWhite") {
            return "F8F8FF";
        } else if (arg1 == "Gold") {
            return "FFD700";
        } else if (arg1 == "Goldenrod") {
            return "DAA520";
        } else if (arg1 == "Gray" || arg1 == "Grey") {
            return "808080";
        } else if (arg1 == "Green") {
            return "008000";
        } else if (arg1 == "GreenYellow") {
            return "ADFF2F";
        } else if (arg1 == "Honeydew") {
            return "F0FFF0";
        } else if (arg1 == "HotPink") {
            return "FF69B4";
        } else if (arg1 == "IndianRed") {
            return "CD5C5C";
        } else if (arg1 == "Indigo") {
            return "4B0082";
        } else if (arg1 == "Ivory") {
            return "FFFFF0";
        } else if (arg1 == "Khaki") {
            return "F0E68C";
        } else if (arg1 == "Lavender") {
            return "E6E6FA";
        } else if (arg1 == "LavenderBlush") {
            return "FFF0F5";
        } else if (arg1 == "LawnGreen") {
            return "7CFC00";
        } else if (arg1 == "LemonChiffon") {
            return "FFFACD";
        } else if (arg1 == "LightBlue") {
            return "ADD8E6";
        } else if (arg1 == "LightCoral") {
            return "F08080";
        } else if (arg1 == "LightCyan") {
            return "E0FFFF";
        } else if (arg1 == "LightGoldenrodYellow") {
            return "FAFAD2";
        } else if (arg1 == "LightGreen") {
            return "90EE90";
        } else if (arg1 == "LightGrey") {
            return "D3D3D3";
        } else if (arg1 == "LightPink") {
            return "FFB6C1";
        } else if (arg1 == "LightSalmon") {
            return "FFA07A";
        } else if (arg1 == "LightSeaGreen") {
            return "20B2AA";
        } else if (arg1 == "LightSkyBlue") {
            return "87CEFA";
        } else if (arg1 == "LightSlateGray" || arg1 == "LightSlateGrey") {
            return "778899";
        } else if (arg1 == "LightSteelBlue") {
            return "B0C4DE";
        } else if (arg1 == "LightYellow") {
            return "FFFFE0";
        } else if (arg1 == "Lime") {
            return "00FF00";
        } else if (arg1 == "LimeGreen") {
            return "32CD32";
        } else if (arg1 == "Linen") {
            return "FAF0E6";
        } else if (arg1 == "Maroon") {
            return "800000";
        } else if (arg1 == "MediumAquamarine") {
            return "66CDAA";
        } else if (arg1 == "MediumBlue") {
            return "0000CD";
        } else if (arg1 == "MediumOrchid") {
            return "BA55D3";
        } else if (arg1 == "MediumPurple") {
            return "9370DB";
        } else if (arg1 == "MediumSeaGreen") {
            return "3CB371";
        } else if (arg1 == "MediumSlateBlue") {
            return "7B68EE";
        } else if (arg1 == "MediumSpringGreen") {
            return "00FA9A";
        } else if (arg1 == "MediumTurquoise") {
            return "48D1CC";
        } else if (arg1 == "MediumVioletRed") {
            return "C71585";
        } else if (arg1 == "MidnightBlue") {
            return "191970";
        } else if (arg1 == "MintCream") {
            return "F5FFFA";
        } else if (arg1 == "MistyRose") {
            return "FFE4E1";
        } else if (arg1 == "Moccasin") {
            return "FFE4B5";
        } else if (arg1 == "NavajoWhite") {
            return "FFDEAD";
        } else if (arg1 == "Navy") {
            return "000080";
        } else if (arg1 == "OldLace") {
            return "FDF5E6";
        } else if (arg1 == "Olive") {
            return "808000";
        } else if (arg1 == "OliveDrab") {
            return "6B8E23";
        } else if (arg1 == "Orange") {
            return "FFA500";
        } else if (arg1 == "OrangeRed") {
            return "FF4500";
        } else if (arg1 == "Orchid") {
            return "DA70D6";
        } else if (arg1 == "PaleGoldenrod") {
            return "EEE8AA";
        } else if (arg1 == "PaleGreen") {
            return "98FB98";
        } else if (arg1 == "PaleTurquoise") {
            return "AFEEEE";
        } else if (arg1 == "PaleVioletRed") {
            return "DB7093";
        } else if (arg1 == "PapayaWhip") {
            return "FFEFD5";
        } else if (arg1 == "PeachPuff") {
            return "FFDAB9";
        } else if (arg1 == "Peru") {
            return "CD853F";
        } else if (arg1 == "Pink") {
            return "FFC0CB";
        } else if (arg1 == "Plaid") {
            return "CC5533";
        } else if (arg1 == "Plum") {
            return "DDA0DD";
        } else if (arg1 == "PowderBlue") {
            return "B0E0E6";
        } else if (arg1 == "Purple") {
            return "800080";
        } else if (arg1 == "Red") {
            return "FF0000";
        } else if (arg1 == "RosyBrown") {
            return "BC8F8F";
        } else if (arg1 == "RoyalBlue") {
            return "4169E1";
        } else if (arg1 == "SaddleBrown") {
            return "8B4513";
        } else if (arg1 == "Salmon") {
            return "FA8072";
        } else if (arg1 == "SandyBrown") {
            return "F4A460";
        } else if (arg1 == "SeaGreen") {
            return "2E8B57";
        } else if (arg1 == "Seashell") {
            return "FFFF5EE";
        } else if (arg1 == "Sienna") {
            return "A0522D";
        } else if (arg1 == "Silver") {
            return "C0C0C0";
        } else if (arg1 == "SkyBlue") {
            return "87CEEB";
        } else if (arg1 == "SlateBlue") {
            return "6A5ACD";
        } else if (arg1 == "SlateGray" || arg1 == "SlateGrey") {
            return "708090";
        } else if (arg1 == "Snow") {
            return "FFFAFA";
        } else if (arg1 == "SpringGreen") {
            return "00FF7F";
        } else if (arg1 == "SteelBlue") {
            return "4682B4";
        } else if (arg1 == "Tan") {
            return "D2B48C";
        } else if (arg1 == "Teal") {
            return "008080";
        } else if (arg1 == "Thistle") {
            return "D8BFD8";
        } else if (arg1 == "Tomato") {
            return "FF6347";
        } else if (arg1 == "Turquoise") {
            return "40E0D0";
        } else if (arg1 == "Violet") {
            return "EE82EE";
        } else if (arg1 == "Wheat") {
            return "F5DEB3";
        } else if (arg1 == "White") {
            return "FFFFFF";
        } else if (arg1 == "WhiteSmoke") {
            return "F5F5F5";
        } else if (arg1 == "Yellow") {
            return "FFFF00";
        } else if (arg1 == "YellowGreen") {
            return "9ACD32";
        } else {
            return "!ERROR!";
        }


    }

private slots:

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
