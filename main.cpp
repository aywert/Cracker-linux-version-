#include "INCLUDE/GeneralLib.h"
#include "INCLUDE/Constants.h"

CrackStatus CrackCode(void);



int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({ Width, Height }), "Crack");

    //Background sprite setting
    sf::Texture backgroundTex;
    if (!backgroundTex.loadFromFile("AnonimusConvertedGif.png"))
    {
        printf("BackgroundTex wasn't initialized due to mistake in openning AnonimusConvertedGif.png");
        return 0;
    }
    sf::Sprite background(backgroundTex);
    background.setPosition({ 0.f, 0.f });
    //-----------------------------------

    //Button sprite setting
    sf::Texture bloodTex;
    if (!bloodTex.loadFromFile("blood.png"))
    {
        printf("BloodTex wasn't initialized due to mistake in openning Blood.png");
        return 0;
    }
    sf::Sprite button(bloodTex);
    button.setPosition({ 150.f, 200.f });
    //-----------------------------------

    //Setting font and output string
    sf::Font font;

    if (!font.loadFromFile("SehnsuchtFont.ttf"))
    {
        printf("Font wasn't initialized due to mistake in openning SehnsuchtFont.ttf");
        return 0;
    }

    sf::Text text; // a font is required to make a text object
    text.setFont(font); 
    text.setString("Crack Me"); // set the string to display
    text.setCharacterSize(24); //set the character size in pixels, not points!
    text.setFillColor(sf::Color::White); // set the color
    text.setPosition({ 165.f, 205.f });
    //-------------------------------------------

    //Soundtrack setting
    sf::SoundBuffer MusicBuffer;
    if (!MusicBuffer.loadFromFile("backgrdMusic.wav"))
    {
        printf("Buffer wasn't initialized due to mistake in openning backgrdMusic.wav");
        return 0;
    }
    // load something into the sound buffer...

    sf::Sound sound;
    sound.setBuffer(MusicBuffer);
    sound.play();
    
    //End of soundteack setting

    //initializating variable
    size_t iteration = 0;
    int FrameX = 0;
    int FrameY = 0;
    bool OnButton        = false;
    bool ButtonIsPressed = false;
    //-----------------------------------------------------


    // run the program as long as the window is open
    while (window.isOpen())
    {
        iteration++;
        sf::Event event;

        // check all the window's events that were triggered since the last iteration of the loop
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.scancode == sf::Keyboard::Scan::Escape)
                    window.close();
            }

            if (event.type == sf::Event::MouseMoved)
            {
                if (150 <= event.mouseMove.x && event.mouseMove.x <= 350 && 
                    200 <= event.mouseMove.y && event.mouseMove.y <= 280)
                {
                    OnButton = true;
                    printf("%d %d: \n", event.mouseMove.x, event.mouseMove.y);
                    button.setColor(sf::Color::Green);      // green
                }

                else
                {
                    if (OnButton == true)
                    {
                        button.setColor(sf::Color::Red);    // red
                        OnButton = false;
                    }
                }
            }

            if (OnButton && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                ButtonIsPressed = true;

                
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left && OnButton && ButtonIsPressed)
                {
                    printf("Initialising Crack\n");
                    if (CrackCode() == FailCrack)
                        printf("Please try again unable to crack due to a mistake\n");
                    else-
                        printf("Cracked\n");
                }

                else
                    ButtonIsPressed = false;
            }
        }

        //handeling cases of background sprite 
        if ((iteration) % 6 == 0)
        {
            FrameX -= ShiftFrameBackX;  //background.move({ 5*506.f, -284.f });
            FrameY += Height;
        }
        else
            FrameX += Width;            //background.move({ -506.f, 0.f });

        if (iteration == NumOfFrames)
        {
            FrameX -=  3 * Width;       //background.move({ 3 * 506.f , 13 * 284.f });
            FrameY -= ShiftFrameBackY;
            iteration = 0;
        }

        background.setTextureRect(sf::IntRect({ FrameX, FrameY }, { Width, Height }));

        usleep(MlsPerFrame);            //sets 80 ms so that background look nice
        
        //--------------------------------------------------

        window.clear();
        window.draw(background);        //draw backdround to buffer
        window.draw(button);            //draw blood button to buffer
        window.draw(text);              //draw "Crack me" string to buffer
        window.display();
    }
}

