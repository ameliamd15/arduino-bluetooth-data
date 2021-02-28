#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface WTBLETool : NSObject


+ (NSString *)ConvertHexStringToString:(NSString *)hexString;

+ (NSString *)ConvertStringToHexString:(NSString *)string;

+(NSData *)ConvertIntToData:(int)i;

+(int)ConvertDataToInt:(NSData *)data;

+ (Byte *)ConvertDataToByte:(NSData *)data;

+ (NSData *)ConvertHexStringToData:(NSString *)hexString;

+(CBCharacteristic *)findCharacteristicFormServices:(NSMutableArray *)services
                                         UUIDString:(NSString *)UUIDString;

@end
