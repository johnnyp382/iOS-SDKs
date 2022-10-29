#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UITabBarItem.h>)
//
//  UITabBarItem.h
//  UIKit
//
//  Copyright (c) 2008-2018 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIBarItem.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UISpringLoadedInteractionSupporting.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

typedef NS_ENUM(NSInteger, UITabBarSystemItem) {
    UITabBarSystemItemMore,
    UITabBarSystemItemFavorites,
    UITabBarSystemItemFeatured,
    UITabBarSystemItemTopRated,
    UITabBarSystemItemRecents,
    UITabBarSystemItemContacts,
    UITabBarSystemItemHistory,
    UITabBarSystemItemBookmarks,
    UITabBarSystemItemSearch,
    UITabBarSystemItemDownloads,
    UITabBarSystemItemMostRecent,
    UITabBarSystemItemMostViewed,
};

@class UIView, UIImage, UITabBarAppearance;

UIKIT_EXTERN API_AVAILABLE(ios(2.0)) NS_SWIFT_UI_ACTOR
@interface UITabBarItem : UIBarItem 

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;
/* The unselected image is autogenerated from the image argument. The selected image
 is autogenerated from the selectedImage if provided and the image argument otherwise.
 To prevent system coloring, provide images with UIImageRenderingModeAlwaysOriginal (see UIImage.h)
 */
- (instancetype)initWithTitle:(nullable NSString *)title image:(nullable UIImage *)image tag:(NSInteger)tag;
- (instancetype)initWithTitle:(nullable NSString *)title image:(nullable UIImage *)image selectedImage:(nullable UIImage *)selectedImage API_AVAILABLE(ios(7.0));
- (instancetype)initWithTabBarSystemItem:(UITabBarSystemItem)systemItem tag:(NSInteger)tag;

@property(nullable, nonatomic,strong) UIImage *selectedImage API_AVAILABLE(ios(7.0));

@property(nullable, nonatomic, copy) NSString *badgeValue;    // default is nil

/*  These methods are now deprecated. Please use -initWithTitle:image:selectedImage:.
 */
- (void)setFinishedSelectedImage:(nullable UIImage *)selectedImage withFinishedUnselectedImage:(nullable UIImage *)unselectedImage API_DEPRECATED("Use initWithTitle:image:selectedImage: or the image and selectedImage properties along with UIImageRenderingModeAlwaysOriginal", ios(5.0, 7.0)) API_UNAVAILABLE(tvos);
- (nullable UIImage *)finishedSelectedImage API_DEPRECATED("", ios(5.0, 7.0)) API_UNAVAILABLE(tvos);
- (nullable UIImage *)finishedUnselectedImage API_DEPRECATED("", ios(5.0, 7.0)) API_UNAVAILABLE(tvos);

/* To set item label text attributes use the appearance selectors available on the superclass, UIBarItem.

   Use the following to tweak the relative position of the label within the tab button (for handling visual centering corrections if needed because of custom text attributes)
 */
@property (nonatomic, readwrite, assign) UIOffset titlePositionAdjustment API_AVAILABLE(ios(5.0)) UI_APPEARANCE_SELECTOR;

/// If this item displays a badge, this color will be used for the badge's background. If set to nil, the default background color will be used instead.
@property (nonatomic, readwrite, copy, nullable) UIColor *badgeColor API_AVAILABLE(ios(10.0)) UI_APPEARANCE_SELECTOR;

/// Provide text attributes to use to draw the badge text for the given singular control state (Normal, Disabled, Focused, Selected, or Highlighted). Default values will be supplied for keys that are not provided by this dictionary. See NSAttributedString.h for details on what keys are available.
- (void)setBadgeTextAttributes:(nullable NSDictionary<NSAttributedStringKey,id> *)textAttributes forState:(UIControlState)state API_AVAILABLE(ios(10.0)) UI_APPEARANCE_SELECTOR;

/// Returns attributes previously set via -setBadgeTextAttributes:forState:.
- (nullable NSDictionary<NSAttributedStringKey,id> *)badgeTextAttributesForState:(UIControlState)state API_AVAILABLE(ios(10.0)) UI_APPEARANCE_SELECTOR;

///  When set and this item is selected, overrides the hosting tab bar's standardAppearance.
@property (nonatomic, readwrite, copy, nullable) UITabBarAppearance *standardAppearance UI_APPEARANCE_SELECTOR API_AVAILABLE(ios(13.0), tvos(13.0));
///  When set and this item is selected, overrides the hosting tab bar's scrollEdgeAppearance.
@property (nonatomic, readwrite, copy, nullable) UITabBarAppearance *scrollEdgeAppearance UI_APPEARANCE_SELECTOR API_AVAILABLE(ios(15.0));
@end

#if TARGET_OS_IOS
@interface UITabBarItem (SpringLoading) <UISpringLoadedInteractionSupporting>
@end
#endif

NS_HEADER_AUDIT_END(nullability, sendability)

#else
#import <UIKitCore/UITabBarItem.h>
#endif