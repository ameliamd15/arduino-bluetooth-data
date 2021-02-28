#import <Foundation/Foundation.h>
#import "WTBLESDK.h"

@interface WTBLEPeripheral : NSObject

@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, strong) NSDictionary *advertisementData;
@property (nonatomic, strong) NSNumber *RSSI;

+ (WTBLEPeripheral *)peripheralWithCBPeripheral:(CBPeripheral *)peripheral
                              advertisementData:(NSDictionary *)advertisementData
                                           RSSI:(NSNumber *)RSSI;
@end
