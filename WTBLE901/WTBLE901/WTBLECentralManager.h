#import <Foundation/Foundation.h>
#import "WTBLECallback.h"
#import "WTBLETool.h"

@interface WTBLECentralManager : NSObject

@property (nonatomic, copy) NSString *peripheralFilter;
@property (nonatomic, strong) WTBLECallback *callback;
@property (nonatomic, copy) void(^characteristicValueUpdateBlock)(CBCharacteristic *characteristic, NSError *error);

- (void)startScan;

- (void)cancelScan;

- (void)tryConnectPeripheral:(CBPeripheral *)peripheral;

- (void)cancelConnection;

- (void)tryReceiveDataAfterConnected;

- (void)writeData:(NSData *)data;

@end
