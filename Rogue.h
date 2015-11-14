#ifdef ROGUECOARSE

class Rogue
{
public:
	Rogue(int color, int rate);
	~Rogue();

	/* data */
	Color Bullet; // The bullet color to paint the lane
	int ShotRate; // Rate/s required to shoot the lanes
	int Success; // Rate/s of lanes shot by ROGUE   
};

/* Define the correlated lock based on the parameters */
class My_Lock
{
public:
    void lock_init(){if_lock = 0;};
    int check_lock();
    int set_lock();
    int release_lock();
    
private:
    int if_lock;      /* If the lanes are locked */
};

int My_Lock::check_lock()
{
    return if_lock;   /* If locked return 1, if not return 0 */
}

int My_Lock::set_lock()
{
    if (if_lock == 1) {  /* The lanes are already locked, lock failed */
        return 0;
    }else{
        if_lock = 1;     /* The lanes are not locked, lock the lanes */
        return 1;
    }
}

int My_Lock::release_lock()
{
    if (if_lock == 0) {  /* The lanes are not locked, release failed */
        return 0;
    }else{
        if_lock = 0;     /* Release lock successfully */
        return 1;
    }
}

#ifdef ROGUECOARSECLEANER

class Cleaner
{
public:
    Cleaner();
    ~Cleaner();
    
    /* data */
    Color Bullet; // The bullet color to paint the lane
    int ShotRate; // Rate/s required to shoot the lanes
    int Success; // Rate/s of lanes shot by ROGUE
};

#endif

#endif


#ifdef ROGUEFINE

class Rogue
{
public:
    Rogue(int color, int rate);
    ~Rogue();
    
    /* data */
    Color Bullet; // The bullet color to paint the lane
    int ShotRate; // Rate/s required to shoot the lanes
    int Success; // Rate/s of lanes shot by ROGUE
};

#endif


#ifdef ROGUETM

class Rogue
{
public:
    Rogue(int color, int rate);
    ~Rogue();
    
    /* data */
    Color Bullet; // The bullet color to paint the lane
    int ShotRate; // Rate/s required to shoot the lanes
    int Success; // Rate/s of lanes shot by ROGUE
};

#endif


#ifdef ROGUECOARSE2

class Rogue
{
public:
    Rogue(int color, int rate);
    ~Rogue();
    
    /* data */
    Color Bullet; // The bullet color to paint the lane
    int ShotRate; // Rate/s required to shoot the lanes
    int Success; // Rate/s of lanes shot by ROGUE
};

#ifdef ROGUECOARSECLEANER

class Cleaner
{
public:
    Cleaner();
    ~Cleaner();
    
    /* data */
    Color Bullet; // The bullet color to paint the lane
    int ShotRate; // Rate/s required to shoot the lanes
    int Success; // Rate/s of lanes shot by ROGUE
};

#endif

#endif


#ifdef ROGUEFINE2

class Rogue
{
public:
    Rogue(int color, int rate);
    ~Rogue();
    
    /* data */
    Color Bullet; // The bullet color to paint the lane
    int ShotRate; // Rate/s required to shoot the lanes
    int Success; // Rate/s of lanes shot by ROGUE
};

class My_Lock
{
public:
    void lock_init(){if_lock = 0;};
    int check_lock();
    int set_lock();
    int release_lock();
    
private:
    int if_lock;      /* If the lanes are locked */
};

int My_Lock::check_lock()
{
    return if_lock;   /* If locked return 1, if not return 0 */
}

int My_Lock::set_lock()
{
    if (if_lock == 1) {  /* The lanes are already locked, lock failed */
        return 0;
    }else{
        if_lock = 1;     /* The lanes are not locked, lock the lanes */
        return 1;
    }
}

int My_Lock::release_lock()
{
    if (if_lock == 0) {  /* The lanes are not locked, release failed */
        return 0;
    }else{
        if_lock = 0;     /* Release lock successfully */
        return 1;
    }
}


#endif


#ifdef ROGUETM2

class Rogue
{
public:
    Rogue(int color, int rate);
    ~Rogue();
    
    /* data */
    Color Bullet; // The bullet color to paint the lane
    int ShotRate; // Rate/s required to shoot the lanes
    int Success; // Rate/s of lanes shot by ROGUE
};

#endif


#ifdef ROGUEFINECLEANER

class Cleaner
{
public:
    Cleaner();
    ~Cleaner();
    
    /* data */
    Color Bullet; // The bullet color to paint the lane
    int ShotRate; // Rate/s required to shoot the lanes
    int Success; // Rate/s of lanes shot by ROGUE
};

#endif


#ifdef ROGUETMCLEANER

class Cleaner
{
public:
    Cleaner();
    ~Cleaner();
    
    /* data */
    Color Bullet; // The bullet color to paint the lane
    int ShotRate; // Rate/s required to shoot the lanes
    int Success; // Rate/s of lanes shot by ROGUE
};

#endif