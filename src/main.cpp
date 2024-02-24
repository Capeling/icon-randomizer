#include <Geode/Geode.hpp>
#include <Geode/modify/CharacterColorPage.hpp>

using namespace geode::prelude;

class $modify(CharacterColorPageExt, CharacterColorPage) {
	bool init() {
		if(!CharacterColorPage::init())
			return false;

		CCMenu* buttonsMenu = getChildOfType<CCMenu>(m_mainLayer, 0);

		ButtonSprite* randomSpr = ButtonSprite::create("Rand", 40, false, "bigFont.fnt", "GJ_button_04.png", 20, 0.4);
		randomSpr->setScale(0.85);
		CCMenuItemSpriteExtra* randomButton = CCMenuItemSpriteExtra::create(randomSpr, this, menu_selector(CharacterColorPageExt::onRand));
		auto col1Btn = getChildOfType<CCMenuItemSpriteExtra>(buttonsMenu, 2);
		randomButton->setPosition({col1Btn->getPositionX() - 50, col1Btn->getPositionY()});

		buttonsMenu->addChild(randomButton);
		return true;
	}
	void onRand(CCObject*) {
		createQuickPopup("Randomize Icons", "Are you sure you want to <cr>randomize</c> your icons?\n<cy>This action cannot be undone.</c>", "No", "Yes",
		[this](auto, bool btn2) {
			if(btn2) {
				randomIcons();
			}
		});
	}
	void randomIcons() {
		log::info("randomize icons");
		GameManager* GM = GameManager::sharedState();
		srand(time(NULL));
		GM->setPlayerFrame(std::rand() % 484 + 1);
		GM->setPlayerShip(std::rand() % 169 + 1);
		GM->setPlayerBall(std::rand() % 118 + 1);
		GM->setPlayerBird(std::rand() % 149 + 1);
		GM->setPlayerDart(std::rand() % 96 + 1);
		GM->setPlayerRobot(std::rand() % 68 + 1);
		GM->setPlayerSpider(std::rand() % 69 + 1);
		GM->setPlayerSwing(std::rand() % 43 + 1);
		GM->setPlayerJetpack(std::rand() % 5 + 1);
		GM->setPlayerStreak(std::rand() % 7 + 1);
		GM->setPlayerShipStreak(std::rand() % 6 + 1);
		GM->setPlayerDeathEffect(std::rand() % 20 + 1);
		GM->setPlayerColor(std::rand() % 106 + 1);
		GM->setPlayerColor2(std::rand() % 106 + 1);
		GM->setPlayerColor3(std::rand() % 106 + 1);
		GM->setPlayerGlow(std::rand() % 2); 

		auto garage = (GJGarageLayer*)this->getParent();

		auto newChar = CharacterColorPage::create();
		newChar->m_noElasticity = true;

		//IT WORKS IM SORRY :SOB:
		garage->addChild(newChar, 100);
	}
};