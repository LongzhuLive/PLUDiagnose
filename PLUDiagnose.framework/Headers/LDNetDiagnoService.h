//
//  LDNetDiagnoService.h
//  LDNetDiagnoServieDemo
//
//  Created by 庞辉 on 14-10-29.
//  Copyright (c) 2014年 庞辉. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @protocol 监控网络诊断的过程信息
 *
 */
@protocol LDNetDiagnoServiceDelegate <NSObject>
/**
 * 告诉调用者诊断开始
 */
- (void)netDiagnosisDidStarted;


/**
 * 逐步返回监控信息，
 * 如果需要实时显示诊断数据，实现此接口方法
 */
- (void)netDiagnosisStepInfo:(NSString *)stepInfo;


/**
 *  返回当前网络类型
 *
 *  @param networkType <#networkType description#>
 */
- (void)netDiagnosisNetworkType: (NSString *)networkType;
/**
 *  返回本地IP信息
 */
- (void)netDiagnosisIp: (NSString *)localIp localGateway: (NSString *)localGateway localDns: (NSString *)localDns;
/**
 * 返回Ping延迟信息
 *
 */
- (void)netDiagnosisPingDelay:(NSString *)domain delayedMs: (NSInteger)delayedMs;
/**
 *  返回出口IP信息
 */
- (void)netDiagnosisOuterIp: (NSString *)outIp ipArea: (NSString *)ipArea outDns: (NSString *)outDns dnsArea: (NSString *)dnsArea isSameArea: (BOOL)isSameArea;

/**
 * 因为监控过程是一个异步过程，当监控结束后告诉调用者；
 * 在监控结束的时候，对监控字符串进行处理
 */
- (void)netDiagnosisDidEnd:(NSString *)allLogInfo;


@end


/**
 * @class 网络诊断服务
 * 通过对指定域名进行ping诊断和traceRoute诊断收集诊断日志
 */
@interface LDNetDiagnoService : NSObject {
}
@property (nonatomic, weak, readwrite)
    id<LDNetDiagnoServiceDelegate> delegate;      //向调用者输出诊断信息接口
@property (nonatomic, retain) NSString *dormain;  //接口域名

@property (nonatomic, assign) BOOL noRoutetrace;

/**
 * 初始化网络诊断服务
 * theAppCode,theUID, theDormain为必填项
 */
- (id)initWithAppCode:(NSString *)theAppCode
              appName:(NSString *)theAppName
           appVersion:(NSString *)theAppVersion
               userID:(NSString *)theUID
             deviceID:(NSString *)theDeviceID
              dormain:(NSString *)theDormain
          carrierName:(NSString *)theCarrierName
       ISOCountryCode:(NSString *)theISOCountryCode
    MobileCountryCode:(NSString *)theMobileCountryCode
        MobileNetCode:(NSString *)theMobileNetCode;

- (void)addDomain: (NSString *)desc domain: (NSString *)domain;


/**
 * 开始诊断网络
 */
- (void)startNetDiagnosis;


/**
 * 停止诊断网络
 */
- (void)stopNetDialogsis;

/**
 *打印需要的网络信息
 */
- (void)recordStepInfo:(NSString *)stepInfo;

/**
 * 打印整体loginInfo；
 */
- (void)printLogInfo;

@end
