package com.keenjackdaw.keen.core.launcher;

import com.keenjackdaw.keen.core.app.Application;

public interface Launcher {
    /**
     * Launch application
     * @param application application to be launched
     */
    void launch(Application application);


    /**
     * Init launcher
     */
    void init();


    /**
     * Stop launcher
     */
    void stop();


    /**
     * Get application
     * @return Application
     */
    Application getApplication();

    /**
     * Set application
     * @param application Application
     */
    void setApplication(Application application);
}
