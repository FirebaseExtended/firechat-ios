//
//  ViewController.h
//  Firechat
//
//  Copyright (c) 2012 Firebase.
//
//  No part of this project may be copied, modified, propagated, or distributed
//  except according to terms in the accompanying LICENSE file.
//

#import <UIKit/UIKit.h>
#import <Firebase/Firebase.h>

@interface ViewController : UIViewController

@property (nonatomic, strong) NSMutableArray* chat;

@property (weak, nonatomic) IBOutlet UITextField *textField;
@property (weak, nonatomic) IBOutlet UITableView *tableView;

@end
