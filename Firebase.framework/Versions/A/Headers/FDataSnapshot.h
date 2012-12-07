//
//  FDataSnapshot.h
//  Firebase
//
//  Created by Vikrum Nijjar on 9/6/12.
//
//

#import <Foundation/Foundation.h>
#import "Firebase.h"

@class Firebase;

/**
 * A DataSnapshot contains data from a Firebase location. Any time you read 
 * Firebase data, you receive the data as a DataSnapshot.
 *
 * DataSnapshots are passed to the event callbacks you attach with on: or once:.
 * They are efficiently-generated immutable copies of the data at a Firebase location.
 * They can't be modified and will never change. To modify data, 
 * you always use a Firebase reference (e.g. with set:).
 */
@interface FDataSnapshot : NSObject

/**
 * Converts the contents of this data snapshot to native objects.
 *
 * Data types returned:
 * * NSDictionary
 * * NSArray
 * * NSNumber (also includes booleans)
 * * NSString
 *
 * @return The data as a native object.
 */
- (id) val;

/**
 * Get a FDataSnapshot for the location at the specified relative path.
 * The relative path can either be a simple child name (e.g. 'fred') 
 * or a deeper slash-separated path (e.g. 'fred/name/first'). If the child
 * location has no data, an empty FDataSnapshot is returned.
 *
 * @param childPathString A relative path to the location of child data.
 * @return The FDataSnapshot for the child location.
 */
- (FDataSnapshot *) child:(NSString *)childPathString;

/**
 * Return true if the specified child exists.
 *
 * @param childPathString A relative path to the location of a potential child.
 * @return True if data exists at the specified childPathString, else false.
 */
- (BOOL) hasChild:(NSString *)childPathString;

/**
 * Get the priority of the data in this FDataSnapshot.
 *
 * @return The priority as a string, or nil if no priority was set.
 */
- (NSString *) getPriority;

/**
 * Enumerate through the FDataSnapshot’s children (in priority order).
 * The provided callback will be called synchronously with a FDataSnapshot for each child.
 *
 * @param action A function which will be called for each child FDataSnapshot.
 *   The callback can return true to cancel further enumeration.
 * @return true if enumeration was canceled due to your callback returning true.
 */
- (BOOL) forEach:(fbt_bool_datasnapshot)action;

/**
 * Return true if the DataSnapshot has any children.
 * 
 * @return True if this snapshot has any children, else false.
 */
- (BOOL) hasChildren;

/**
 * Get the name of the location that generated this FDataSnapshot.
 *
 * @return A NSString containing the name for the location of this FDataSnapshot.
 */
- (NSString *) name;

/**
 * Get the number of children for this DataSnapshot.
 *
 * @return An integer indicating the number of children.
 */
- (int) numChildren;

@property (nonatomic, strong) Firebase* ref;

@end
