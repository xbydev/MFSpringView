//
//  MFSpringView.h
//  MFSpringView
//
//  Created by Lyman Li on 2018/11/25.
//  Copyright © 2018年 Lyman Li. All rights reserved.
//

#import <GLKit/GLKit.h>

@class MFSpringView;

@protocol MFSpringViewDelegate <NSObject>

- (void)springViewStretchAreaDidChanged:(MFSpringView *)springView;

@end

@interface MFSpringView : GLKView

@property (nonatomic, weak) id <MFSpringViewDelegate> springDelegate;
@property (nonatomic, assign, readonly) BOOL hasChange; // 拉伸区域是否被拉伸

/**
 将区域拉伸或压缩为某个高度

 @param startY 开始的纵坐标位置
 @param endY 结束的纵坐标位置
 @param newHeight 新的高度
 */
- (void)stretchingFromStartY:(CGFloat)startY
                      toEndY:(CGFloat)endY
               withNewHeight:(CGFloat)newHeight;

/**
 纹理顶部的纵坐标 0～1

 @return 纹理顶部的纵坐标
 */
- (CGFloat)textureTopY;

/**
 纹理底部的纵坐标 0～1

 @return 纹理底部的纵坐标
 */
- (CGFloat)textureBottomY;

/**
 可伸缩区域顶部的纵坐标 0～1

 @return 可伸缩区域顶部的纵坐标
 */
- (CGFloat)stretchAreaTopY;

/**
 可伸缩区域底部的纵坐标 0～1

 @return 可伸缩区域底部的纵坐标
 */
- (CGFloat)stretchAreaBottomY;

/**
 纹理高度 0～1

 @return 纹理高度
 */
- (CGFloat)textureHeight;

/**
 获取当前的渲染结果
 */
- (UIImage *)createResult;

/**
 根据当前的拉伸结果来重新生成纹理
 */
- (void)updateTexture;

/**
 更新图片

 @param isNew 是否新的图片
 */
- (void)updateImage:(UIImage *)image isNew:(BOOL)isNew;

@end
