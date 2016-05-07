//
// Created by sky on 15-9-10.
//

#ifndef MUTIL_THREAD_YTHREAD_H
#define MUTIL_THREAD_YTHREAD_H

#include <pthread.h>
#include <semaphore.h>


/*
 *
 * Create a new thread
 *
 *Arguments Analyse :
 *
 *NewThread_ID : pthread_t *
 *NewThread_Attribute: pthread_attr_t *
 *NewThread_StartRoutine :  void *(*__start_routine) (void *)
 *StartRoutine_Func_Arg: void *
 *
 *return : int
 * */
#define Y_THREAD_CREATE(NewThread_ID, NewThread_Attribute, NewThread_StartRoutine, StartRoutine_Func_Arg)\
          pthread_create( (NewThread_ID), (NewThread_Attribute), (NewThread_StartRoutine), (StartRoutine_Func_Arg))


/*
 *
 * Wait a thread return
 *
 *Arguments Analyse :
 *
 *WaitThread_ID: pthread_t
 *WaitThread_Re_Value: void **
 *
 *return : int
 * */
#define  Y_THREAD_JOIN(WaitThread_ID, WaitThread_Re_Value) \
        pthread_join( (WaitThread_ID) , (WaitThread_Re_Value) )


/*
 *
 * Exit a thread
 *
 * Arguments Analyse :
 *
 * Exit_Code : void *
 *
 *
 * return : int
 * */
#define Y_THREAD_EXIT(Exit_Code) \
        pthread_exit(Exit_Code)


/**************************************************/
/*
 *
 *
 *
 * 修改线程的属性
 *
 *
 *
 *
 *
 * */
/**************************************************/



/************************
 *
 *
 * 关于线程的绑定，牵涉到另外一个概念：轻进程（LWP：Light Weight Process）。
 * 轻进程可以理解为内核线程，它位于用户层和系统层之间。系统对线程资源的分配、
 * 对线程的控制是通过轻进程来实现的，一个轻进程可以控制一个或多个线程。默认状况下，
 * 启动多少轻进程、哪些轻进程来控制哪些线程是由系统来控制的，这种状况即称为非绑定的。
 * 绑定状况下，则顾名思义，即某个线程固定的"绑"在一个轻进程之上。被绑定的线程具有较高的响应速度，
 * 这是因为CPU时间片的调度是面向轻进程的，绑定的线程可以保证在需要的时候它总有一个轻进程可用。
 * 通过设置被绑定的轻进程的优先级和调度级可以使得绑定的线程满足诸如实时反应之类的要求.
 * 设置线程绑定状态的函数为 pthread_attr_setscope，它有两个参数，第一个是指向属性结构的指针，
 * 第二个是绑定类型，它有两个取值：PTHREAD_SCOPE_SYSTEM（绑定的）和PTHREAD_SCOPE_PROCESS（非绑定的）。
 *
 *
 *
 * *********************/


/*
 *
 * Init the pthread_attr_t 's value.
 *
 * Arguments Analyse :
 *
 * attribute:pthread_attr_t *
 *
 *return : int
 * */

#define Y_THREAD_INITATTRIBUTE(attribute)\
                pthread_attr_init(attribute)




/*
 *
 *Set Scope for a thread(线程的绑定属性的设置)
 *
 * Arguments Analyse :
 *
 * attribute : pthread_attr_t *
 * scope : int
 *
 * return : int
 * */

#define Y_THREAD_SETSCOPE(attribute, scope) \
        pthread_attr_setscope( (attribute), (scope) )


/*
 *
 * A:  线程的分离状态决定一个线程以什么样的方式来终止自己。
 * 在上面的例子中，我们采用了线程的默认属性，即为非分离状态，
 * 这种情况下，原有的线程等待创建的线程结束。只有当pthread_join（）函数返回时，
 * 创建的线程才算终止，才能释放自己占用的系统资源。而分离线程不是这样子的，它没有被其他的线程所等待，
 * 自己运行结束了，线程也就终止了，马上释放系统资源。程序员应该根据自己的需要，选择适当的分离状态。
 * 设置线程分离状态的函数为 pthread_attr_setdetachstate（pthread_attr_t *attr, int detachstate）。
 * 第二个参数可选为PTHREAD_CREATE_DETACHED（分离线程）和 PTHREAD _CREATE_JOINABLE（非分离线程）。
 * 这里要注意的一点是，如果设置一个线程为分离线程，而这个线程运行又非常快，它很可能在 pthread_create函数返回之前就终止了，
 * 它终止以后就可能将线程号和系统资源移交给其他的线程使用，这样调用pthread_create的线程就得到了错误的线程号。
 * 要避免这种情况可以采取一定的同步措施，最简单的方法之一是可以在被创建的线程里调用 pthread_cond_timewait函数，
 * 让这个线程等待一会儿，留出足够的时间让函数pthread_create返回。设置一段等待时间，是在多线程编程里常用的方法。
 * 但是注意不要使用诸如wait（）之类的函数，它们是使整个进程睡眠，并不能解决线程同步的问题。
 *
 *
 *
 *
 * B:   另外一个可能常用的属性是线程的优先级，它存放在结构sched_param中。
 * 用函数pthread_attr_getschedparam和函数 pthread_attr_setschedparam进行存放，
 * 一般说来，我们总是先取优先级，对取得的值修改后再存放回去
 *
 *
 *
 * 要使用的headerfile    #include <sched.h>
 * */



//线程设置为是否分离
/*
 *
 * Set thread if it detaches
 *
 * Arguments Analyse :
 *
 * attribute:pthread_attr_t *
 *
 * detachstate: int (The value of it is PTHREAD_CREATE_DETACHED（分离线程）和 PTHREAD _CREATE_JOINABLE（非分离线程）)
 *
 *
 * return : int
 *
 * */



#define Y_THREAD_ATTR_SETDETACHSTATE(attribute, detachstate)\
            pthread_attr_setdetachstate（attribute, detachstate）

//线程优先级操作
/*
 *
 * Get sched param
 *
 *  Arguments Analyse :
 *
 * attribute:pthread_attr_t *
 * param:sched_param *
 *
 * return : int
 *
 * */
#define Y_THREAD_ATTR_GETSCHEDPARAM(attribute, param)\
                    pthread_attr_getschedparam(attribute, param)



/*
 *
 * Set sched param
 *
 *
 *  Arguments Analyse :
 *
 *  attribute:pthread_attr_t *
 *  param:sched_param *
 *
 *  return : int
 *
 * */

#define Y_THREAD_ATTR_SETSCHEDPARAM(attribute, param)\
                    pthread_attr_setschedparam(attribute, param)






/**************************************************/
/*
 *
 *
 *
 * 线程之间的数据操作 part
 *
 *
 *
 *
 *
 * */
/**************************************************/



/*
 *
 *  和进程相比，线程的最大优点之一是数据的共享性，各个进程共享父进程处沿袭的数据段，
 * 可以方便的获得、修改数据。但这也给多线程编程带来了许多问题。我们必须当心有多个不同的进程访问相同的变量。
 * 许多函数是不可重入的，即同时不能运行一个函数的多个拷贝（除非使用不同的数据段）。在函数中声明的静态变量常常带来问题，
 * 函数的返回值也会有问题。因为如果返回的是函数内部静态声明的空间的地址，则在一个线程调用该函数得到地址后使用该地址指向的数据时，
 * 别的线程可能调用此函数并修改了这一段数据。在进程中共享的变量必须用关键字volatile来定义，
 * 这是为了防止编译器在优化时（如gcc中使用-OX参数）改变它们的使用方式。为了保护变量，
 * 我们必须使用信号量、互斥等方法来保证我们对变量的正确使用。
 *
 *
 *
 * */



//线程数据（TSD: Thread-Specific Data）的使用


/*
 *
 * Create a key for a thread
 *
 * Arguments Analyse :
 *
 * key:pthread_key_t *
 *
 * destr_func_for_key: void (*__destr_function) (void *)
 *
 *
 * return : int
 * */
#define Y_THREAD_KEY_CREATE(key, destr_func_for_key)\
            pthread_key_create(key, destr_func_for_key)



/*
 *
 *  为了让键只被创建一次
 *
 *  Arguments Analyse :
 *
 *  once_control: pthread_once_t *
 *
 *  init_func: void (*initroutine) (void)
 *
 *  return : int
 *
 * */

#define Y_THREAD_ONCE(once_control, init_func)\
            pthread_once (once_control, init_func)

/*
 *
 * Set Key for value
 *
 * Arguments Analyse :
 *
 * key :pthread_key_t
 * pointer: __const void *
 *
 * return : int
 * */


#define Y_THREAD_SETSPECIFIC(key, pointer)\
            pthread_setspecific (key, pointer)



/*
 *
 * Get Key for value
 *
 * Arguments Analyse :
 *
 * key :pthread_key_t
 *
 * return : void *
 * */

#define  Y_THREAD_GETSPECIFIC(key)\
            pthread_getspecific (key)



//互斥锁的使用


/*
 *
 * Init a mutex(声明普通mutex)
 *
 *Arguments Analyse :
 *
 *mutex : pthread_mutex_t
 *
 *mutexattr: const pthread_mutexattr_t *
 *
 * return : int
 * */


#define Y_THREAD_MUTEX_INIT(mutex, mutexattr)\
            pthread_mutex_init(mutex , mutexattr)



/*
 *
 * 函数pthread_mutexattr_setpshared和函数 pthread_mutexattr_settype用来设置互斥锁属性。
 * 前一个函数设置属性pshared，它有两个取值，PTHREAD_PROCESS_PRIVATE和PTHREAD_PROCESS_SHARED。
 * 前者用来不同进程中的线程同步，后者用于同步本进程的不同线程。在上面的例子中，我们使用的是默认属性PTHREAD_PROCESS_ PRIVATE。
 * 后者用来设置互斥锁类型，可选的类型有PTHREAD_MUTEX_NORMAL、PTHREAD_MUTEX_ERRORCHECK、
 * PTHREAD_MUTEX_RECURSIVE和PTHREAD _MUTEX_DEFAULT。它们分别定义了不同的上所、解锁机制，一般情况下，选用最后一个默认属性。
 *
 *
 *
 *
 * */



/*
 *
 * Init a mutex(声明特别mutex)
 *
 *Arguments Analyse :
 *
 *
 * attr : pthread_mutexattr_t *
 *
 * return : int
 * */


#define  Y_THREAD_MUTEXATTR_INIT(attr)\
        pthread_mutexattr_init(attr)



/*
 *
 * Lock several codelines
 *
 * Arguments Analyse :
 *
 * mutex: pthread_mutex_t *
 *
 * return : int
 * */

#define Y_THREAD_MUTEX_LOCK(mutex)\
            pthread_mutex_lock(mutex)





/*
 *
 * Unlock several codelines
 *
 * Arguments Analyse :
 *
 * mutex: pthread_mutex_t *
 *
 *
 * return : int
 * */

#define Y_THREAD_MUTEX_UNLOCK(mutex)\
            pthread_mutex_unlock(mutex)




/*
 * 而条件变量通过允许线程阻塞和等待另一个线程发送信号的方法弥补了互斥锁的不足，
 * 它常和互斥锁一起使用。使用时，条件变量被用来阻塞一个线程，当条件不满足时，
 * 线程往往解开相应的互斥锁并等待条件发生变化。一旦其它的某个线程改变了条件变量，
 * 它将通知相应的条件变量唤醒一个或多个正被此条件变量阻塞的线程。这些线程将重新锁定互斥锁并重新测试条件是否满足。
 * 一般说来，条件变量被用来进行线程间的同步。
 *
 *
 * */

//条件变量的使用

/*
 *
 * Initialize condition variable
 *
 * Arguments Analyse :
 *
 * cond : pthread_cond_t *
 *
 * cond_attr: pthread_condattr_t *
 *
 *
 * return : int
 * */

#define Y_THREAD_COND_INIT(cond, cond_attr)\
            pthread_cond_init(cond, cond_attr)


/*
 *
 *  Wake up one thread waiting for condition variable COND.
 *
 *  Arguments Analyse :
 *
 *  cond:pthread_cond_t *
 *
 *  return : int
 * */

#define Y_THREAD_COND_SIGNAL(cond)\
            pthread_cond_signal(cond)



/*
 *
 * Wait for condition variable COND to be signaled or broadcast.
 * MUTEX is assumed to be locked before.
 * This function is a cancellation point and therefore not marked with__THROW.
 *
 *  Arguments Analyse :
 *
 *
 *  cond:pthread_cond_t *
 *
 *  mutex:pthread_mutex_t *
 *
 *  return : int
 *
 * */

#define Y_THREAD_COND_WAIT(cond, mutex)\
            pthread_cond_wait(cond, mutex)



//信号量


/*
 *
 *Initialize semaphore object SEM to VALUE.  If PSHARED then share it with other processes.
 *
 *
 * Arguments Analyse :
 * value 参数指定信号量的初始值。
 * pshared 参数指明信号量是由进程内线程共享，
 * 还是由进程之间共享。如果 pshared 的值为 0，
 * 那么信号量将被进程内的线程共享，
 * 并且应该放置在这个进程的所有线程都可见的地址上(如全局变量，或者堆上动态分配的变量)。
 *
 * sem: sem_t *
 *
 * pshared:int
 *
 * value:unsigned int
 *
 *
 * return : int
 *
 *
 * */

#define Y_SEM_INIT(sem, pshared, value)\
            sem_init(sem, pshared, value)


/*
 *
 * Post SEM.
 *
 *
 * Arguments Analyse :
 *
 * sem: sem_t *
 *
 * return : int
 * */

#define  Y_SEM_WAIT(sem) \
            sem_wait (sem)

/*
 *
 * Wait for SEM being posted.
 * This function is a cancellation point and therefore not marked with__THROW.
 *
 *
 * Arguments Analyse :
 *
 * sem: sem_t *
 *
 * return : int
 *
 * */

#define Y_SEM_POSET(sem)\
            sem_post(sem)


/*
 *
 * This a test
 *
 * */

#define Add(a, b) \
(\
{\
\
    int sum_test;\
    sum_test  = (a)+(b);\
    ++sum_test;\
}\
)










#endif //MUTIL_THREAD_YTHREAD_H_H
