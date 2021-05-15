DIGITALNOTE_VERSION = 1.0.3.4

DIGITALNOTE_LIB_LEVELDB_DIR = $${DIGITALNOTE_PATH}/src/leveldb
DIGITALNOTE_LIB_LEVELDB_NEW_DIR = $${DIGITALNOTE_PATH}/src/leveldb-2.11
DIGITALNOTE_LIB_SECP256K1_DIR = $${DIGITALNOTE_PATH}/src/secp256k1

win32 {
	## Config your lib directory names
	DIGITALNOTE_LIB_BOOST_DIR = $${DIGITALNOTE_PATH}/../libs/boost_1_75_0
	DIGITALNOTE_LIB_BOOST_SUFFIX = -mgw7-mt-d-x64-1_75
	DIGITALNOTE_LIB_OPENSSL_DIR = $${DIGITALNOTE_PATH}/../libs/openssl-1.0.2u
	DIGITALNOTE_LIB_BDB_DIR = $${DIGITALNOTE_PATH}/../libs/db-6.2.32.NC
	DIGITALNOTE_LIB_EVENT_DIR = $${DIGITALNOTE_PATH}/../libs/libevent-2.1.11-stable
	DIGITALNOTE_LIB_GMP_DIR = $${DIGITALNOTE_PATH}/../libs/gmp-6.2.1
	DIGITALNOTE_LIB_MINIUPNP_DIR = $${DIGITALNOTE_PATH}/../libs/miniupnpc-2.1
	DIGITALNOTE_LIB_QRENCODE_DIR = $${DIGITALNOTE_PATH}/../libs/qrencode-4.1.1
}

macx {
	DIGITALNOTE_MAC_SDK_DIR = /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs
	DIGITALNOTE_MAC_SDK_VERSION = 10.15
	DIGITALNOTE_MAC_SDK_VERSION_MIN = 10.13
	
	DIGITALNOTE_LIB_BOOST_DIR = /usr/local/Cellar/boost/1.74.0
	DIGITALNOTE_LIB_OPENSSL_DIR = /usr/local/Cellar/openssl@1.1/1.1.1h
	
	DIGITALNOTE_MAC_QMAKE_FLAGS = -mmacosx-version-min=$${DIGITALNOTE_MAC_SDK_VERSION_MIN} -isysroot $${DIGITALNOTE_MAC_SDK_DIR}/MacOSX$${DIGITALNOTE_MAC_SDK_VERSION}.sdk
	
	QMAKE_CXXFLAGS += $${DIGITALNOTE_MAC_QMAKE_FLAGS}
	QMAKE_CFLAGS += $${DIGITALNOTE_MAC_QMAKE_FLAGS}
	QMAKE_LFLAGS += $${DIGITALNOTE_MAC_QMAKE_FLAGS}
	QMAKE_OBJECTIVE_CFLAGS += $${DIGITALNOTE_MAC_QMAKE_FLAGS}
	
	HEADERS += src/qt/macdockiconhandler.h
	HEADERS += src/qt/macnotificationhandler.h
	
	OBJECTIVE_SOURCES += src/qt/macdockiconhandler.mm
	OBJECTIVE_SOURCES += src/qt/macnotificationhandler.mm
	
	LIBS += -framework Foundation
	LIBS += -framework ApplicationServices
	LIBS += -framework AppKit
	LIBS += -framework CoreServices
	
	DEFINES += MAC_OSX
	DEFINES += MSG_NOSIGNAL=0
	
	ICON = src/qt/res/icons/digitalnote.icns
}
