//
//  BFPeripheralDelegate.h
//  BlueFoundation
//
//  Created by Xin Wang on 7/27/16.
//  Copyright © 2016 EtchingLab. All rights reserved.
//

#import <Foundation/Foundation.h>

@import CoreBluetooth;

@class BFPeripheralManager;

typedef NS_ENUM(uint8_t, BFPeripheralDelegateState) {
    BFPeripheralDelegateStateIdle = 0,
    BFPeripheralDelegateStateConnected,
    BFPeripheralDelegateStateDiscoveringServices,
    BFPeripheralDelegateStateDiscoveringCharacteristics,
    BFPeripheralDelegateStateReady,
    BFPeripheralDelegateStateWriteWithNotify,
    BFPeripheralDelegateStateWriteWithoutNotify,
    BFPeripheralDelegateStateWriteThenRead,
    BFPeripheralDelegateStateRead,
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^BFPeripheralDelegateConnectHandler)(NSError * _Nullable error);
typedef void (^BFPeripheralDelegateDidDiscoverServicesAndCharacteristicsHandler)(NSError * _Nullable error);
typedef void (^BFPeripheralDelegateReadRSSIHandler)(NSNumber *RSSI, NSError * _Nullable error);
typedef void (^BFPeripheralDelegateWriteWithNotifyHandler)(NSData * _Nullable response, NSError * _Nullable error);
typedef void (^BFPeripheralDelegateWriteWithoutNotifyHandler)(NSError * _Nullable error);
typedef void (^BFPeripheralDelegateWriteThenReadHandler)(NSData * _Nullable response, NSError * _Nullable error);
typedef void (^BFPeripheralDelegateReadHandler)(NSData * _Nullable response, NSError * _Nullable error);

@interface BFPeripheralDelegate : NSObject <CBPeripheralDelegate>

@property (nonatomic, weak, nullable) BFPeripheralManager *manager;
@property (nonatomic, strong, nullable) NSMutableDictionary<NSString *, CBCharacteristic *> *mutableCharacteristics;

@property (nonatomic, assign) BFPeripheralDelegateState state;

// callbacks
@property (nonatomic, copy, nullable) BFPeripheralDelegateDidDiscoverServicesAndCharacteristicsHandler didDiscoverServicesAndCharacteriscitcsHandler;
@property (nonatomic, copy, nullable) BFPeripheralDelegateReadRSSIHandler readRSSIHandler;

@property (nonatomic, copy, nullable) BFPeripheralDelegateWriteWithNotifyHandler writeWithNotifyHandler;
@property (nonatomic, copy, nullable) BFPeripheralDelegateWriteWithoutNotifyHandler writeWithoutNotifyHandler;
@property (nonatomic, copy, nullable) BFPeripheralDelegateWriteThenReadHandler writeThenReadHandler;
@property (nonatomic, copy, nullable) BFPeripheralDelegateReadHandler readHandler;



@end

NS_ASSUME_NONNULL_END
