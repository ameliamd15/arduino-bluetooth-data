#import <CoreBluetooth/CoreBluetooth.h>

typedef void (^WTCentralManagerDidUpdateStateBlock)(CBCentralManager *central);
typedef void (^WTDiscoverPeripheralsBlock)(CBCentralManager *central, CBPeripheral *peripheral, NSDictionary *advertisementData, NSNumber *RSSI);
typedef void (^WTConnectedPeripheralBlock)(CBCentralManager *central, CBPeripheral *peripheral);
typedef void (^WTFailToConnectBlock)(CBCentralManager *central, CBPeripheral *peripheral, NSError *error);
typedef void (^WTDisconnectBlock)(CBCentralManager *central, CBPeripheral *peripheral, NSError *error);
typedef void (^WTDiscoverServicesBlock)(CBPeripheral *peripheral,NSError *error);
typedef void (^WTDiscoverCharacteristicsBlock)(CBPeripheral *peripheral,CBService *service,NSError *error);

typedef void (^WTReadValueForCharacteristicBlock)(CBPeripheral *peripheral,CBCharacteristic *characteristic,NSError *error);

typedef void (^WTDiscoverDescriptorsForCharacteristicBlock)(CBPeripheral *peripheral,CBCharacteristic *service,NSError *error);

typedef void (^WTReadValueForDescriptorsBlock)(CBPeripheral *peripheral,CBDescriptor *descriptor,NSError *error);

typedef void (^WTDidWriteValueForCharacteristicBlock)(CBCharacteristic *characteristic,NSError *error);

typedef void (^WTDidWriteValueForDescriptorBlock)(CBDescriptor *descriptor,NSError *error);

@interface WTBLECallback : NSObject

#pragma mark - callback block

@property (nonatomic, copy) WTCentralManagerDidUpdateStateBlock blockOnCentralManagerDidUpdateState;

@property (nonatomic, copy) WTDiscoverPeripheralsBlock blockOnDiscoverPeripherals;

@property (nonatomic, copy) WTConnectedPeripheralBlock blockOnConnectedPeripheral;

@property (nonatomic, copy) WTFailToConnectBlock blockOnFailToConnect;

@property (nonatomic, copy) WTDisconnectBlock blockOnDisconnect;
 
@property (nonatomic, copy) WTDiscoverServicesBlock blockOnDiscoverServices;

@property (nonatomic, copy) WTDiscoverCharacteristicsBlock blockOnDiscoverCharacteristics;

@property (nonatomic, copy) WTReadValueForCharacteristicBlock blockOnReadValueForCharacteristic;

@property (nonatomic, copy) WTDiscoverDescriptorsForCharacteristicBlock blockOnDiscoverDescriptorsForCharacteristic;
@property (nonatomic, copy) WTReadValueForDescriptorsBlock blockOnReadValueForDescriptors;

@property (nonatomic, copy) WTDidWriteValueForCharacteristicBlock blockOnDidWriteValueForCharacteristic;

@property (nonatomic, copy) WTDidWriteValueForDescriptorBlock blockOnDidWriteValueForDescriptor;
@end
