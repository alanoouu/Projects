#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Awards.h"

using namespace awards;
using namespace testing;

using namespace std;

class RankListStub : public RankList {
private:
	string recipient;

	string recipients [3] = {"bob", "ken", "joe"};

	// Also the number of times the getNext() function is called
	int numAwardsAwarded = 0;
public:
	string getNext() {
		if (numAwardsAwarded < 3) {
			recipient = recipients[numAwardsAwarded];
			numAwardsAwarded++;
			return recipient;
		}
	}

	// Getter for the number of awards awarded
	int getnumAwardsAwarded() {
        return numAwardsAwarded;
    }
};

class AwardCeremonyActionsMock : public AwardCeremonyActions {
public:
  	MOCK_METHOD0(playAnthem, void());
    MOCK_METHOD1(awardBronze, void(string recipient));
    MOCK_METHOD1(awardSilver, void(string recipient));
    MOCK_METHOD1(awardGold, void(string recipient));
    MOCK_METHOD0(turnOffTheLightsAndGoHome, void());
};

TEST(AwardsTests, performAwardCeremony) {
	RankListStub rankList;
	AwardCeremonyActionsMock awardCeremonyActions;

	InSequence seq;	
	EXPECT_CALL(awardCeremonyActions, playAnthem())
		.Times(1);
	EXPECT_CALL(awardCeremonyActions, awardBronze("bob"))
		.Times(1);
	EXPECT_CALL(awardCeremonyActions, awardSilver("ken"))
		.Times(1);
	EXPECT_CALL(awardCeremonyActions, awardGold("joe"))
		.Times(1);
	EXPECT_CALL(awardCeremonyActions, turnOffTheLightsAndGoHome())
		.Times(1);
	
	performAwardCeremony(rankList, awardCeremonyActions);

	ASSERT_EQ(3, rankList.getnumAwardsAwarded());
}

