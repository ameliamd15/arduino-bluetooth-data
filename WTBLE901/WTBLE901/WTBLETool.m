#import "WTBLETool.h"

@implementation WTBLETool

+ (NSString *)ConvertHexStringToString:(NSString *)hexString {
    
    char *myBuffer = (char *)malloc((int)[hexString length] / 2 + 1);
    bzero(myBuffer, [hexString length] / 2 + 1);
    for (int i = 0; i < [hexString length] - 1; i += 2) {
        unsigned int anInt;
        NSString * hexCharStr = [hexString substringWithRange:NSMakeRange(i, 2)];
        NSScanner *scanner = [[NSScanner alloc] initWithString:hexCharStr];
        [scanner scanHexInt:&anInt];
        myBuffer[i / 2] = (char)anInt;
    }
    NSString *unicodeString = [NSString stringWithCString:myBuffer encoding:4];
    return unicodeString;
}

+ (NSString *)ConvertStringToHexString:(NSString *)string {
    NSData *myD = [string dataUsingEncoding:NSUTF8StringEncoding];
    Byte *bytes = (Byte *)[myD bytes];
    NSString *hexStr=@"";
    for (int i=0;i<[myD length];i++) {
        NSString *newHexStr = [NSString stringWithFormat:@"%x",bytes[i]&0xff];
        if ([newHexStr length]==1) {
            hexStr = [NSString stringWithFormat:@"%@0%@",hexStr,newHexStr];
        }
        else{
            hexStr = [NSString stringWithFormat:@"%@%@",hexStr,newHexStr];
        }
        
    }
    return hexStr;
}

+ (NSData *)ConvertIntToData:(int)i {
    
    NSData *data = [NSData dataWithBytes: &i length: sizeof(i)];
    return data;
}

+ (int)ConvertDataToInt:(NSData *)data {
    int i;
    [data getBytes:&i length:sizeof(i)];
    return i;
}

+ (Byte *)ConvertDataToByte:(NSData *)data {
    NSUInteger len = [data length];
    Byte *byte = (Byte *)malloc(len);
    memcpy(byte, [data bytes], len);
    return byte;
}

+ (NSData *)ConvertHexStringToData:(NSString *)hexString {
    
    NSData *data = [[WTBLETool ConvertHexStringToString:hexString] dataUsingEncoding:NSUTF8StringEncoding];
    return data;
}

+ (CBCharacteristic *)findCharacteristicFormServices:(NSMutableArray *)services
                                          UUIDString:(NSString *)UUIDString {
    for (CBService *s in services) {
        for (CBCharacteristic *c in s.characteristics) {
            if ([c.UUID.UUIDString isEqualToString:UUIDString]) {
                return c;
            }
        }
    }
    return nil;
}

@end
