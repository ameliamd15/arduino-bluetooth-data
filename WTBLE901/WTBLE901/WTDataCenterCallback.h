#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, WTPortMode) {
    WTPortMode_AnalogInput = 1,
    WTPortMode_DigitalInput,
    WTPortMode_HighLevelOutput,
    WTPortMode_LowLevelOutput
};


typedef void (^WTDataCenterUpdateAccBlock)(double ax, double ay, double az, double total);

typedef void (^WTDataCenterUpdateAngularVBlock)(double wx, double wy, double wz, double total);

typedef void (^WTDataCenterUpdateAngleBlock)(double roll, double pitch, double yaw);

typedef void (^WTDataCenterUpdateMagneticBlock)(double mx, double my, double mz, double m);

typedef void (^WTDataCenterUpdatePressureBlock)(double p, double h);

typedef void (^WTDataCenterUpdateTempuratureBlock)(double t);

typedef void (^WTDataCenterUpdateQuaternionBlock)(double q0, double q1, double q2, double q3);

typedef void (^WTDataCenterUpdatePortBlock)(double d0, double d1, double d2, double d3);

typedef void (^WTDataCenterUpdateBLENameBlock)(BOOL isSuccess, NSError *error);

@interface WTDataCenterCallback : NSObject

@property (nonatomic, copy) WTDataCenterUpdateAccBlock blockOnUpdateAcc;

@property (nonatomic, copy) WTDataCenterUpdateAngularVBlock blockOnUpdateAngularV;

@property (nonatomic, copy) WTDataCenterUpdateAngleBlock blockOnUpdateAngle;

@property (nonatomic, copy) WTDataCenterUpdateMagneticBlock blockOnUpdateMagnetic;

@property (nonatomic, copy) WTDataCenterUpdatePressureBlock blockOnUpdatePressure;

@property (nonatomic, copy) WTDataCenterUpdateTempuratureBlock blockOnUpdateTempurature;

@property (nonatomic, copy) WTDataCenterUpdateQuaternionBlock blockOnUpdateQuaternion;

@property (nonatomic, copy) WTDataCenterUpdatePortBlock blockOnUpdatePort;

@property (nonatomic, copy) WTDataCenterUpdateBLENameBlock blockOnUpdateBLEName;

@end
