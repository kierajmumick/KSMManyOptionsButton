//
//  KSMManyOptionsButton.h
//  KSMManyOptionsButton
//
//  Created by Kieraj Mumick on 7/16/14.
//  Copyright (c) 2014 Chaiwalla. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol KSMManyOptionsButtonDelegate;

/**
 *  An enumeration for the different locations of buttons on the 
 *  KSMManyOptionsButton view.
 *
 *  @author Kieraj S. Mumick
 *  @copyright 2014, Chaiwalla
 */
typedef NS_ENUM(NSUInteger, KSMManyOptionsButtonLocation) {
    KSMManyOptionsButtonLocationTop,    /// The location above the center button.
    KSMManyOptionsButtonLocationBottom, /// The location below the center button.
    KSMManyOptionsButtonLocationLeft,   /// The location left of the center button.
    KSMManyOptionsButtonLocationRight   /// The location right of the center button.
};

/**
 *  An enumeration for the different states of the KSMManyOptionsButtonView
 *
 *  @author Kieraj S. Mumick
 *  @copyright 2014, Chaiwalla
 */
typedef NS_ENUM(NSUInteger, KSMManyOptionsButtonState) {
    KSMManyOptionsButtonStateOpen,    /// The state for when all of the buttons on the view are showing.
    KSMManyOptionsButtonStateClosed,  /// The state for when only the center button is showing.
    KSMManyOptionsButtonStateExpanded /// The state for when one of the outer buttons is highlighted
};

/**
 *  The class for creating a many options button. This is a type of button that
 *  when clicked, shows other possible selections the user can make. These selections
 *  can be made through swiping or multiselections.
 *
 *  @author Kieraj S. Mumick
 *  @copyright 2014, Chaiwalla
 */
@interface KSMManyOptionsButton : UIControl

/// Image that will be displayed at the respective location on the KSMManyOptionsButton @author Kieraj S. Mumick
@property (strong, nonatomic) UIImage *leftButtonImage,
                                      *rightButtonImage,
                                      *topButtonImage,
                                      *bottomButtonImage;

/// Images that will be displayed when one of the buttons is highlighted
@property (strong, nonatomic) UIImage *highlightedLeftButtonImage,
                                      *highlightedRightButtonImage,
                                      *highlightedTopButtonImage,
                                      *highlightedBottomButtonImage;

/// Image that will be displayed as teh center button on the KSMManyOptionsButton. @author Kieraj S. Mumick
@property (strong, nonatomic) UIImage *centerButtonImage;

/// Image that will be used when the center button is highlighted
@property (strong, nonatomic) UIImage *highlightedCenterButtonImage;

/// Holds the current state of the view. @author Kieraj S. Mumick
@property (nonatomic) KSMManyOptionsButtonState currentManyOptionsButtonState;

/// Holds the current locations where there are buttons. @author Kieraj S. Mumick
@property (readonly, strong, nonatomic) NSArray *locationsArray;

/// The size to use for the frame when the button is in the KSMManyOptionsButtonStateClosed.
@property (readonly, nonatomic) CGSize closedSize;
/// The size to use for the frame when the button is in the KSMManyOptionsButtonStateOpen.
@property (readonly, nonatomic) CGSize openedSize;

/// The delegate object for this view
@property (weak, nonatomic) id<KSMManyOptionsButtonDelegate> delegate;

/// A transformation that will be performed to the center button when the KSMManyOptionsButton is in the closed state.
@property (nonatomic) CGAffineTransform transformForCenterButtonWhenClosed;


/**
 *  Custom initializer for when the frame, and all of the images for all of the buttons
 *  around the view are known.
 *
 *  @param frame             The frame for the view.
 *  @param centerButtonImage The UIImage for the button that will always be displayed in
 *                           the center of the view.
 *  @param leftButtonImage   The UIImage for the button that will be displayed to the left
 *                           of the center button when the KSMManyOptionsButton is in open
 *                           mode.
 *  @param rightButtonImage  The UIImage for the button that will be displayed to the right
 *                           of the center button when the KSMManyOptionsButton is in open
 *                           mode.
 *  @param topButtonImage    The UIImage for the button that will be displayed to the top
 *                           of the center button when the KSMManyOptionsButton is in open
 *                           mode.
 *  @param bottomButtonImage The UIImage for the button that will be displayed to the left
 *                           of the center button when the KSMManyOptionsButton is in open
 *                           mode.
 *
 *  @return An instance of the KSMManyOptionsButton with all of the provided arguements as
 *          the images for each of its views.
 *
 *  @author Kieraj S. Mumick
 */
- (instancetype)initWithFrame:(CGRect)frame
            centerButtonImage:(UIImage *)centerButtonImage
              leftButtonImage:(UIImage *)leftButtonImage
             rightButtonImage:(UIImage *)rightButtonImage
               topButtonImage:(UIImage *)topButtonImage
         andBottomButtonImage:(UIImage *)bottomButtonimage;

/**
 *  Custom initializer for when the frame, and all of the images for all of the buttons
 *  around the view are known.
 *
 *  If any of the buttons images are set to nil, that means that there will be no button at
 *  that location and the delegate method will not be called for any interation at that location
 *  on the view. If you would like to have user interaction on one of the sides of the view, but
 *  also have no image there, you can specify that image to be <code>[UIImage new]</code>
 *
 *  @param centerButtonImage The UIImage for the button that will always be displayed in
 *                           the center of the view.
 *  @param leftButtonImage   The UIImage for the button that will be displayed to the left
 *                           of the center button when the KSMManyOptionsButton is in open
 *                           mode.
 *  @param rightButtonImage  The UIImage for the button that will be displayed to the right
 *                           of the center button when the KSMManyOptionsButton is in open
 *                           mode.
 *  @param topButtonImage    The UIImage for the button that will be displayed to the top
 *                           of the center button when the KSMManyOptionsButton is in open
 *                           mode.
 *  @param bottomButtonImage The UIImage for the button that will be displayed to the left
 *                           of the center button when the KSMManyOptionsButton is in open
 *                           mode.
 *
 *  @return An instance of the KSMManyOptionsButton with all of the provided arguements as
 *          the images for each of its views.
 *
 *  @author Kieraj S. Mumick
 */
- (instancetype)initWithCenterButtonImage:(UIImage *)centerButtonImage
                          leftButtonImage:(UIImage *)leftButtonImage
                         rightButtonImage:(UIImage *)rightButtonImage
                           topButtonImage:(UIImage *)topButtonImage
                     andBottomButtonImage:(UIImage *)bottomButtonimage;

@end


/**
 *  The protocol for the many options button. This protocol informs the delegate object
 *  of the KSMManyOptionsButton that one of the buttons was selected at a specific index.
 *
 *  @author Kieraj S. Mumick
 *  @copyright 2014, Chaiwalla
 */
@protocol KSMManyOptionsButtonDelegate <NSObject>

/**
 *  Informs the delegate object that a button was selected at a specific location on the
 *  KSMManyOptionsButton.
 *
 *  @param button The KSMManyOptionsButton that a button was selected on.
 *  @param location The location on the KSMManyOptionsButton where a button was selected.
 *
 *  @author Kieraj S. Mumick
 */
- (void)manyOptionsButton:(KSMManyOptionsButton *)button didSelectButtonAtLocation:(KSMManyOptionsButtonLocation)location;

@end
