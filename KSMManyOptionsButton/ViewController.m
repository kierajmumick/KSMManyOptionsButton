//
//  ViewController.m
//  KSMManyOptionsButton
//
//  Created by Kieraj Mumick on 7/16/14.
//  Copyright (c) 2014 Chaiwalla. All rights reserved.
//

#import "ViewController.h"
#import "KSMManyOptionsButton.h"

@interface ViewController ()

@end

@implementation ViewController
            
- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    self.view.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"halftone"]];

    UIImage *center = [UIImage imageNamed:@"center"];
    UIImage *left   = [UIImage imageNamed:@"cancel"];
    UIImage *top    = [UIImage imageNamed:@"send"];

    KSMManyOptionsButton *button = [[KSMManyOptionsButton alloc] initWithCenterButtonImage:center
                                                                           leftButtonImage:left
                                                                          rightButtonImage:nil
                                                                            topButtonImage:top
                                                                      andBottomButtonImage:nil];

    button.highlightedTopButtonImage = [UIImage imageNamed:@"sendSelected"];
    button.highlightedLeftButtonImage = [UIImage imageNamed:@"cancelSelected"];

    button.transformForCenterButtonWhenClosed = CGAffineTransformMakeRotation(M_PI / 4);

    button.delegate = self;
    button.center = CGPointMake(CGRectGetMaxX(self.view.bounds) - 25, CGRectGetMaxY(self.view.bounds) - 22);
    [self.view addSubview:button];

    UIImage *camera = [UIImage imageNamed:@"camera"];

    KSMManyOptionsButton *button2 = [[KSMManyOptionsButton alloc] initWithCenterButtonImage:camera
                                                                            leftButtonImage:nil
                                                                           rightButtonImage:left
                                                                             topButtonImage:top
                                                                       andBottomButtonImage:nil];
    button2.highlightedTopButtonImage = [UIImage imageNamed:@"sendSelected"];
    button2.highlightedRightButtonImage = [UIImage imageNamed:@"cancelSelected"];
    
    button2.delegate = self;
    button2.center = CGPointMake(25, CGRectGetMaxY(self.view.bounds) - 22);
    [self.view addSubview:button2];

    UILabel *label = [[UILabel alloc] initWithFrame:self.view.bounds];
    label.text = @"KSMManyOptionsButton";
    label.textAlignment = NSTextAlignmentCenter;
    label.center = CGPointMake(CGRectGetMidX(self.view.bounds), CGRectGetMidY(self.view.bounds));
    [self.view addSubview:label];

}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark KSMManyOptionsButtonDelegate
- (void)manyOptionsButton:(KSMManyOptionsButton *)button didSelectButtonAtLocation:(KSMManyOptionsButtonLocation)location
{
    switch (location) {
        case KSMManyOptionsButtonLocationBottom:
            NSLog(@"Bottom");
            break;
        case KSMManyOptionsButtonLocationLeft:
            NSLog(@"Left");
            break;
        case KSMManyOptionsButtonLocationRight:
            NSLog(@"Right");
            break;
        case KSMManyOptionsButtonLocationTop:
            NSLog(@"Top");
            break;
        default:
            break;
    }
}

@end
