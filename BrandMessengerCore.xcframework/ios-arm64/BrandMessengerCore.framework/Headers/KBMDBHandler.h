//
//  KBMDBHandler.h
//  BrandMessengerCore
//
//  Created by Gaurav Nigam on 09/08/15.
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import <CoreData/CoreData.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMDBHandler` has all the methods for core data operations like inserting, fetching, deleting and updating in core data ManagedObject.
/// @warning `KBMDBHandler` class used only for internal purposes.
@interface KBMDBHandler : NSObject

/// `managedObjectModel` is used in `NSPersistentContainer` init method to configure.
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;

/// `persistentContainer` is has a access for performing operations in core data.
@property (strong, nonatomic) NSPersistentContainer * _Nullable persistentContainer;

/// To check if the NSPersistentContainer is loaded successfully or not.
@property (nonatomic) BOOL isStoreLoaded;

/// To save the main ManagedObject context in core data.
- (NSError * _Nullable)saveContext;

/// Shared instance method of `KBMDBHandler`.
+ (KBMDBHandler *)sharedInstance;

/// Use this method for save the private managed object context  and main managed object context in core data.
/// @param context Pass the private context.
/// @param completion Handler will have error in case of failed to save else error will be nil in case of success save.
- (void)saveWithContext:(NSManagedObjectContext * _Nullable)context
             completion:(void (^)(NSError * _Nullable error))completion;

/// Fetching the data from core database this will require `NSFetchRequest` object for Processing.
/// @param fetchrequest Create a fetch request for fetching array of data.
/// @param fetchError Pass the `NSError` to check the status of fetch request.
- (NSArray * _Nullable)executeFetchRequest:(NSFetchRequest *)fetchrequest withError:(NSError * _Nullable * _Nullable)fetchError;

/// Entities describe the "types" of objects available.
/// @param name Pass the name of the entity.
- (NSEntityDescription * _Nullable)entityDescriptionWithEntityForName:(NSString *)name;

/// Gets Result count for fetch request.
/// @param fetchrequest Fetch request to get the count of objects.
- (NSUInteger)countForFetchRequest:(NSFetchRequest *)fetchrequest;

/// To get the `NSManagedObject` by `NSManagedObjectID` from core data.
/// @param objectID Pass the `ManagedObjectID`.
- (NSManagedObject * _Nullable)existingObjectWithID:(NSManagedObjectID *)objectID;

/// Insert new object in main context for entity name given.
/// @param entityName Pass the name of the entity that data as to be inserted.
- (NSManagedObject * _Nullable)insertNewObjectForEntityForName:(NSString *)entityName;

/// Insert new object in private context for entity name given.
/// @param entityName Pass the name of entity.
/// @param context Pass the context to insert the object.
- (NSManagedObject * _Nullable)insertNewObjectForEntityForName:(NSString *)entityName withManagedObjectContext:(NSManagedObjectContext * _Nullable)context;

/// Deletes the managed object from core database.
/// @param managedObject Pass themanaged object that you want to delete from core data.
- (NSError * _Nullable)deleteObject:(NSManagedObject *)managedObject;

/// Used for performing batch update in core data.
/// @param updateRequest Pass the batch update request.
/// @param fetchError Pass the error in case of any error the object will not be nil else it will be nil in case of success update.
/// @return Returns the NSBatchUpdateResult in case of updated otherwise nil.
- (NSBatchUpdateResult * _Nullable)executeRequestForNSBatchUpdateResult:(NSBatchUpdateRequest *)updateRequest withError:(NSError * _Nullable * _Nullable)fetchError;

@end

NS_ASSUME_NONNULL_END
