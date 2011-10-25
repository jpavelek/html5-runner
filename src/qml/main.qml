import QtQuick 1.1
import com.nokia.meego 1.0
import QtWebKit 1.0

PageStackWindow {
    id: appWindow

    initialPage: mainPage

    Page {
        id: mainPage
        tools: commonTools

        ToolBarLayout {
            id: commonTools
            visible: true

            ToolIcon {
                id: menuButton
                iconId: "toolbar-view-menu"
                onClicked: (mapsMenu.status == DialogStatus.Closed) ? mapsMenu.open() : mapsMenu.close()
            }
        }

        Menu {
            id: mapsMenu
            MenuLayout {
                MenuItem { text: "Exit"; onClicked: Qt.quit() }
            }
        }

        WebView {
            id: webView
            anchors.fill: parent
            url: gotoUri
        }
    }

}


